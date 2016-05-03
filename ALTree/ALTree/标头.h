#pragma once
#include<iostream>
using namespace std;


template<class K, class V>
struct AVLTreeNode
{
	K _key;
	V _value;
	AVLTreeNode<K, V> *_left;
	AVLTreeNode<K, V> *_right;
	AVLTreeNode<K, V> *_parent;
	int _bf;
	AVLTreeNode(const K& key, const V& value)
		:_key(key)
		, _value(value)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _bf(0)
	{

	}
};


template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(NULL)
	{

	}
	bool Insert(const K& key, const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			return true;
		}
		Node *parent = NULL;
		Node *cur = _root;
		while (cur)
		{
			parent = cur;
			if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key, value);
		if (key > parent->_key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		bool isRotate = false;
		//接下来进行平衡因子的调整，因为是从下向上进行调整
		while (parent)
		{


			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;//卧槽！！！！！！！！！我在这调整平衡银子了！！！



			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else//2、-2
			{
				isRotate = true;
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						_RotateL(parent);
					}
					else
					{
						_RotateRL(parent);
					}
				}
				else
				{
					if (cur->_bf == 1)
					{
						_RotateLR(parent);
					}
					else
					{
						_RotateR(parent);
					}
				}
				break;//这个break的作用是什么？
			}
		}
		if (isRotate)
		{
			Node *ppNode = parent->_parent;
			if (ppNode == NULL)
			{
				_root = parent;
			}
			else
			{

				if (ppNode->_key > parent->_key)
				{
					ppNode->_left = parent;
				}
				else
				{
					ppNode->_right = parent;
				}
			}
		}
		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	bool IsBalance()
	{
		return _IsBalance(_root);

	}
protected:
	bool _IsBalance(Node *root)
	{
		if (root == NULL)
		{
			return true;
		}
		int left = _GetDepth(root->_left);
		int right = _GetDepth(root->_right);
		int bf = abs(right - left);
		if (bf != abs(root->_bf))
		{
			cout << root->_key << "平衡因子错了你造么" << endl;
			return false;
		}
		if (bf > 1)
		{
			return false;
		}
		return _IsBalance(root->_left) && _IsBalance(root->_right);
	}
	int _GetDepth(Node *root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		int left = _GetDepth(root->_left);
		int right = _GetDepth(root->_right);
		return left > right ? left + 1 : right + 1;
	}
	void _InOrder(Node *root)
	{
		if (root == NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << "  ";
		_InOrder(root->_right);
	}
	void _RotateL(Node *&parent)
	{
		Node *subR = parent->_right;
		Node *subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		subR->_parent = parent->_parent;
		parent->_parent = subR;
		parent->_bf = 0;
		subR->_bf = 0;
		parent = subR;
	}
	void _RotateR(Node *&parent)
	{
		Node *subL = parent->_left;
		Node *subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		subL->_parent = parent->_parent;
		parent->_parent = subL;
		parent->_bf = 0;
		subL->_bf = 0;
		parent = subL;
	}
	void _RotateLR(Node *&parent)
	{

		_RotateL(parent->_left);

		_RotateR(parent);
	}
	void _RotateRL(Node *&parent)
	{
		_RotateR(parent->_right);
		_RotateL(parent);
	}
protected:
	Node *_root;
};



void TestAVLTree()
{
	AVLTree<int, int> a1;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		a1.Insert(a[i], a[i]);
	}
	a1.InOrder();
	cout << a1.IsBalance() << endl;
}
void test2()
{
	AVLTree<int, int> a1;
	a1.Insert(6,6);
	a1.Insert(7,7);
	a1.Insert(5,5);
	a1.Insert(3,3);
	a1.Insert(4,4);
}
void test3()
{
	AVLTree<int, int> a1;
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		a1.Insert(a[i], a[i]);
	}
	a1.InOrder();
	cout << a1.IsBalance() << endl;
}

void test4()
{
	AVLTree<int, int> a1;
	int a[] = {58,623,4,63,56,245,38,2,46,9};
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		a1.Insert(a[i], a[i]);
	}
	a1.InOrder();
	cout << a1.IsBalance() << endl;
}