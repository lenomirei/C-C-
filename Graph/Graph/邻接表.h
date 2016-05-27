#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

template<class W>
struct ListNode
{
	int _index;
	int _srcindex;
	W _weight;
	ListNode *_next;
	ListNode(int srcindex, int index, const W& weight)
		:_srcindex(srcindex)
		, _index(index)
		, _weight(weight)
		, _next(NULL)
	{}
	bool operator>(const ListNode &ln) const
	{
		return this->_weight > ln._weight;
	}
	bool operator<(const ListNode &ln) const
	{
		return this->_weight < ln._weight;
	}
};




template<class V, class W>
class Graph
{
	typedef ListNode<W> Node;
public:
	Graph(V *vArry, size_t size)
	{
		_list = _Create(vArry, size);
	}
	Graph()
		:_size(0)
		, _vNode(NULL)
		, _list(NULL)
	{

	}
	Node ** _Create(V *vArry, size_t size)
	{
		_size = size;
		_vNode = new V[size];
		for (int i = 0; i < size; ++i)
		{
			_vNode[i] = vArry[i];
		}
		_list = new Node*[_size]();
		return _list;
	}




	int FindIndex(const V& vnode)
	{
		for (int i = 0; i < _size; ++i)
		{
			if (_vNode[i] == vnode)
			{
				return i;
			}
		}
		return -1;
	}
	void _AddEdges(int src, int dst, const W& weight)
	{
		ListNode<W> *cur = _list[src];
		if (cur == NULL)
		{
			_list[src] = new ListNode<W>(src, dst, weight);
			return;
		}
		while (cur->_next)
		{
			if (cur->_index == dst)
			{
				cur->_weight = weight;
				return;
			}//重复输入或者是更新weight的值
			cur = cur->_next;
		}
		cur->_next = new ListNode<W>(src, dst, weight);
	}
	void AddEdges(const V& src, const V& dst, const W& weight)
	{
		int srcindex = FindIndex(src);
		int dstindex = FindIndex(dst);
		_AddEdges(srcindex, dstindex, weight);
		//_AddEdges(dstindex, srcindex, weight);
	}
	void Display()
	{
		for (int i = 0; i < _size; ++i)
		{
			cout << _vNode[i] << "[" << i << "]";
		}
		cout << endl;
		for (int i = 0; i < _size; ++i)
		{
			cout << i << ":" << "->";
			ListNode<W> *cur = _list[i];
			while (cur)
			{
				if (i < cur->_index)
				{
					cout << "[" << cur->_index << "]" << cur->_weight << "->";

				}
				cur = cur->_next;
			}
			cout << "NULL" << endl;
		}
	}
	void DFS(const V& start)//广度优先遍历
	{
		int begin = FindIndex(start);
		int *vertexStatusArr = new int[_size];
		memset(vertexStatusArr, 0, sizeof(int)*_size);
		queue<int> qindex;
		cout << _vNode[begin] << "  ";
		vertexStatusArr[begin] = 1;
		ListNode<W> *cur = _list[begin];
		while (cur)
		{
			qindex.push(cur->_index);
			vertexStatusArr[cur->_index] = 1;
			cur = cur->_next;
		}
		while (!qindex.empty())
		{
			int front = qindex.front();
			qindex.pop();

			cout << _vNode[front] << "  ";
			vertexStatusArr[front] = 1;
			cur = _list[front];
			while (cur)
			{
				if (vertexStatusArr[cur->_index] != 1)
				{
					qindex.push(cur->_index);

				}
				cur = cur->_next;
			}
		}
		cout << endl;
	}
	void BFS(const V& start)//深度优先遍历
	{
		int begin = FindIndex(start);
		int *vertexStatusArr = new int[_size];
		memset(vertexStatusArr, 0, sizeof(int)*_size);
		BFS_core(begin, vertexStatusArr);
		cout << endl;
	}
	void BFS_core(int index, int *vertexStatusArr)
	{
		if (vertexStatusArr[index] == 1)
		{
			return;
		}
		cout << _vNode[index] << "  ";
		vertexStatusArr[index] = 1;
		ListNode<W> *cur = _list[index];
		while (cur)
		{
			BFS_core(cur->_index, vertexStatusArr);
			cur = cur->_next;
		}
	}


	bool Kruskal(Graph<V, W>& minTree)
	{
		minTree._Create(_vNode, _size);
		Heap<Node *> hp;
		for (int i = 0; i < _size; ++i)
		{
			Node *cur = _list[i];
			while (cur)
			{
				if (i < cur->_index)
				{
					hp.Push(cur);
				}
				cur = cur->_next;
			}
		}
		UnionFindSet<int> set(_size);
		while (hp.Size())
		{
			Node *top = hp.GetTop();
			hp.Pop();
			int root1 = set.FindRoot(top->_srcindex);
			int root2 = set.FindRoot(top->_index);
			if (root1 != root2)
			{
				minTree.AddEdges(_vNode[top->_srcindex], _vNode[top->_index], top->_weight);
				set.Combine(root1, root2);
			}
		}
		return true;
	}


	bool Prime(Graph<V, W>& minTree)
	{
		minTree._Create(_vNode, _size);
		Heap<Node *> hp;
		bool *visited = new bool[_size]();
		int src = 0;
		visited[0] = true;
		int count = 1;
		while (count < _size)
		{
			Node *cur = _list[src];
			while (cur)
			{
				if (visited[cur->_index] == false)//没有加入过的节点就可以push辣，否则可是会构成环的哦
				{
					hp.Push(cur);
				}
				cur = cur->_next;
			}


			while (!hp.Empty())
			{
				Node *top = hp.Top();
				hp.Pop();
				if (visited[top->_index] == false)
				{
					//如果dstindex没有添加过就可以添加辣，addedges
					minTree.AddEdges(top->_srcindex, top->_index, top->_weight);
					//	minTree.AddEdges(top->_index, top->_srcindex, top->_weight);//无向图，所以添加两遍
				}

				visited[top->_index] = true;
				src = top->_index;
				count++;
				break;
			}
		}
		return true;
	}
	void Dijkstra(int *path, int *length, int src)
	{
		Dijkstra_core(path, length, src);
		length[src, src] = INT32_MAX;
	}
	void Dijkstra_core(int *path, int *length,int src)
	{
		int lengthsum = 0;
		memset(path, 0, sizeof(int)*_size);
		for (int i = 0; i < _size; ++i)
		{
			length[i] = INT32_MAX;
		}
		
		Heap<Node *> hp;
		int count = 1;

		while (count<_size)
		{
			Node *cur = _list[src];
			if (cur == NULL)
			{
				break;
			}
			while (cur)//update
			{
				if (length[cur->_index] > lengthsum + cur->_weight)
				{
					length[cur->_index] = lengthsum + cur->_weight;
					path[cur->_index] = cur->_srcindex;
				}
				hp.Push(cur);
				cur = cur->_next;
			}//初始化更新就做好了，然后再进行最短路径的更新就好了


			//update

			Node * top = hp.Top();
			lengthsum += top->_weight;
			hp.Clear();
			src = top->_index;
			count++;
		}
	}





protected:
	Node **_list;
	V *_vNode;
	size_t _size;
};


void testGraph1()
{
	int a[] = { 0,1,2,3,4 };
	Graph<int, int> g(a, 5);
	g.AddEdges(0, 2, 10);
	g.AddEdges(3, 4, 30);
	g.AddEdges(4, 1, 20);
	g.AddEdges(2, 3, 50);
	g.Display();
	//g.BFS();
	g.DFS(3);
}
void testGraph2()
{
	char a[] = { 'A' ,'B','C','D','E'};
	Graph<char, int> g(a, 5);
	g.AddEdges('A', 'B', 10);
	g.AddEdges('D', 'C', 30);
	g.AddEdges('E', 'D', 20);
	g.AddEdges('C', 'B', 50);
	g.Display();
	g.BFS('C');
	//g.DFS('C');
}

void testkruskal()
{
	int a[7] = { 0,1,2,3,4,5,6 };
	Graph<int, int> g(a, 7);
	g.AddEdges(0, 1, 28);
	g.AddEdges(0, 5, 10);
	g.AddEdges(1, 2, 16);
	g.AddEdges(1, 6, 14);
	g.AddEdges(2, 3, 12);
	g.AddEdges(6, 3, 18);
	g.AddEdges(6, 4, 24);
	g.AddEdges(3, 4, 22);
	g.AddEdges(4, 5, 25);
	Graph<int, int > b;
	g.Kruskal(b);
}

void testprime()
{
	int a[7] = { 0,1,2,3,4,5,6 };
	Graph<int, int> g(a, 7);
	g.AddEdges(0, 1, 28);
	g.AddEdges(0, 5, 10);
	g.AddEdges(1, 2, 16);
	g.AddEdges(1, 6, 14);
	g.AddEdges(2, 3, 12);
	g.AddEdges(6, 3, 18);
	g.AddEdges(6, 4, 24);
	g.AddEdges(3, 4, 22);
	g.AddEdges(4, 5, 25);
	g.Display();
	Graph<int, int > b;
	cout << g.Prime(b) << endl;
	b.Display();
}

void testDijkstra()
{
	int a[7] = { 0,1,2,3,4,5,6 };
	Graph<int, int> g(a, 7);
	g.AddEdges(1, 2, 10);
	g.AddEdges(2, 4, 40);
	g.AddEdges(4, 0, 20);
	g.AddEdges(0, 3, 10);
	g.AddEdges(3, 1, 20);
	g.AddEdges(0, 2, 50);
	g.AddEdges(0, 4, 50);
	g.Display();
	int *path = new int[7];
	int *length = new int[7];
	g.Dijkstra(path, length,0);
}