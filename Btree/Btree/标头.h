#pragma once
#include<iostream>

using namespace std;


template<class K, int M = 3>
struct BTreeNode
{
	K _keys[M];
	BTreeNode<K, M> *_subs[M + 1];
	size_t _size;
	BTreeNode<K, M> *_parent;
	BTreeNode()
		:_size(0)
		, _parent(NULL)
	{
		for (size_t i = 0; i < M + 1; ++i)
		{
			_subs[i] = NULL;
		}
	}
};

template<class K, int M = 3>
class BTree
{
	typedef BTreeNode<K, M> Node;
	template<class T1, class T2>
	struct Pair
	{
		T1 _first;
		T2 _second;
		Pair(const T1& t1,const T2& t2)
			:_first(t1)
			,_second(t2)
		{

		}
	};
public:
	BTree()
		:_root(NULL)
	{}
	Pair<Node *, int> Find(const K& key)
	{
		Node *parent = NULL;
		Node *cur = _root;
		while (cur)
		{
			int i = 0;
			while (i < cur->_size && key > cur->_keys[i])
			{
				i++;
			}
			if (key == cur->_keys[i])
			{
				return Pair<Node *, int>(cur, i);
			}
			parent = cur;
			cur = cur->_subs[i];
		}
		return Pair<Node *, int>(parent, -1);
	}
	bool Insert(const K& key)
	{
		if (_root == NULL)
		{
			_root = new Node;
			_root->_keys[0] = key;
			_root->_size++;
			return true;
		}
		Pair<Node *, int> result = Find(key);
		if (result._second != -1)//找到了有该节点
		{
			return false;
		}
		Node *cur = result._first;
		K k = key;
		Node *sub = NULL;
		while (1)//如果不存在则进行插入
		{
			_Insertkey(cur, k, sub);
			if (cur->_size < M)
			{
				return true;
			}
			else//进行分裂
			{
				int boundary = M / 2;
				Node *tmp = new Node;
				size_t size = cur->_size;
				size_t index = 0;
				for (size_t i = boundary + 1; i < size; ++i)
				{
					tmp->_subs[index] = cur->_subs[i];
					tmp->_keys[index] = cur->_keys[i];
					index++;
					cur->_size--;
					tmp->_size++;
				}
				tmp->_subs[index] = cur->_subs[size];//把最后一个孩子也拷贝过去

				k = cur->_keys[boundary];
				cur->_size--;

				if (cur->_parent == NULL)//根节点进行分裂
				{
					_root = new Node;
					_root->_keys[0] = cur->_keys[boundary];
					_root->_subs[0] = cur;
					_root->_subs[1] = tmp;
					cur->_parent = _root;
					tmp->_parent = _root;
					_root->_size = 1;
					return true;
				}
				else//非根节点进行分裂
				{
					cur = cur->_parent;
					sub = tmp;
				}
			}
		}
	}

	void InOrder()
	{
		return _InOrder(_root);
	}

	void _Insertkey(Node* cur, const K& key, Node *sub)
	{
		size_t i = cur->_size - 1;
		while (i >= 0)
		{
			if (key < cur->_keys[i])
			{
				cur->_keys[i + 1] = cur->_keys[i];
				cur->_subs[i + 2] = cur->_subs[i + 1];
				i--;
			}
			else
			{
				break;
			}
		}
		cur->_keys[i + 1] = key;
		cur->_subs[i + 2] = sub;
		cur->_size++;
		if (sub)
		{
			sub->_parent = cur;
		}
	}

protected:
	void _InOrder(Node *root)
	{
		if (root == NULL)
		{
			return;
		}
		for (size_t i = 0; i < root->_size; ++i)
		{
			_InOrder(root->_subs[i]);
			cout << root->_keys[i] << "  ";
		}
	}

protected:
	BTreeNode<K, M> *_root;
};



void TestBTree()
{
	BTree<int, 3> bt1;
	int a[] = { 53, 75, 139, 49, 145, 36, 101 };
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		bt1.Insert(a[i]);
	}
	bt1.InOrder();
}