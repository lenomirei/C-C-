#pragma once
#include<iostream>
using namespace std;


template<class K,class V>
struct BSTNode
{
	K _key;
	V _value;
	BSTNode *_left;
	BSTNode *_right;
	BSTNode(const K& key, const V& value)
		:_key(key)
		,_value(value)
		,_left(NULL)
		,_right(NULL)
	{
	}
};






template<class K,class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:
	BSTree()
		:_root(NULL)
	{

	}
	~BSTree()
	{}
	bool Insert(const K& key,const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
		}
		Node *cur = _root;
		Node *parent = _root;
		while (cur)
		{
			parent = cur;
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		if (parent->_key > key)
		{
			parent->_left = new Node(key, value);
		}
		else
		{
			parent->_right = new Node(key, value);
		}
		return true;
	}
	bool Insert_R(const K& key, const V& value)
	{
		return _Insert_R(_root,key,value);
	}
	bool Remove(const K& key)
	{
		if (_root == NULL)
		{
			return false;
		}
		if (_root->_left == NULL && _root->_right == NULL)
		{
			delete _root;
			_root = NULL;
			return true;
		}
		Node *del = _root;
		Node *parent = _root;
		while (del && del->_key != key)
		{
			parent = del;
			if (del->_key > key)
			{
				del = del->_left;
			}
			else if (del->_key < key)
			{
				del = del->_right;
			}
		}
		if (del)
		{
			if (del->_left == NULL || del->_right == NULL)
			{
				if (del->_left == NULL)
				{
					if (parent->_left == del)
					{
						parent->_left = del->_right;
					}
					else
					{
						parent->_right = del->_right;
					}
				}
				else
				{

					if (parent->_left == del)
					{
						parent->_left = del->_left;
					}
					else
					{
						parent->_right = del->_left;
					}
				}
				delete del;
				return true;
			}
			else
			{
				Node *InOrderfirst = del->_right;
				Node *parent = del;
				while (InOrderfirst->_left != NULL)
				{
					parent = InOrderfirst;
					InOrderfirst = InOrderfirst->_left;
				}
				swap(del->_key, InOrderfirst->_key);
				swap(del->_value, InOrderfirst->_value);
				if (InOrderfirst->_left == NULL)
				{
					if (parent->_left == InOrderfirst)
					{
						parent->_left = InOrderfirst->_right;
					}
					else
					{
						parent->_right = InOrderfirst->_right;
					}
				}
				else
				{

					if (parent->_left == InOrderfirst)
					{
						parent->_left = InOrderfirst->_left;
					}
					else
					{
						parent->_right = InOrderfirst->_left;
					}
					
				}
				delete InOrderfirst;
				return true;
			}
		}
		return false;
	}
	bool Remove_R(const K& key)
	{
		return _Remove_R(_root, key);
	}
	Node *Find(const K& key)
	{
		Node *cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return NULL;
	}
	Node *Find_R(const K& key)
	{
		return _Find_R(_root,key);
	}
	void InOrder()
	{
		return _InOrder(_root);
	}
protected:
	bool _Remove_R(Node *&root,const K& key)
	{
		if (root == NULL)
		{
			return false;
		}
		if (root->_key > key)
		{
			return _Remove_R(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _Remove_R(root->_right, key);
		}
		else
		{
			if (root->_left == NULL || root->_right == NULL)
			{
				if (root->_left == NULL)
				{
					Node *del = root;
					root = root->_right;
					delete del;
					return true;
				}
				else
				{
					Node *del = root;
					root = root->_left;
					delete del;
					return true;
				}
			}
			else
			{
				Node *InOrderfirst = root->_right;
				while (InOrderfirst->_left != NULL)
				{
					InOrderfirst = InOrderfirst->_left;
				}
				swap(InOrderfirst->_key, root->_key);
				swap(InOrderfirst->_value, root->_value);
				return _Remove_R(root->_right, key);
			}
		}
	}
	void _InOrder(Node *root)
	{
		if (root == NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	Node *_Find_R(Node *root, const K& key)
	{
		if (root == NULL)
		{
			return NULL;
		}
		if (root->_key < key)
		{
			return _Find_R(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _Find_R(root->_left, key);
		}
		else
		{
			return root;
		}
	}
	bool _Insert_R(Node *&root, const K& key, const V& value)
	{
		if (root == NULL)
		{
			root = new Node(key, value);
			return true;
		}
		
		if (root->_key > key)
		{
			return _Insert_R(root->_left, key, value);
		}
		else if (root->_key < key)
		{
			return _Insert_R(root->_right, key, value);
		}
		else
		{
			return false;
		}
	}
protected:
	Node *_root;
};


void TestBinarySearchTree()
{
	BSTree<int, int> bst1;
	int a[10] = { 5,4,3,1,7,8,2,6,0,9 };
	for (int i = 0; i < 10; ++i)
	{
		bst1.Insert(a[i],a[i]);
	}
//	bst1.InOrder();
	//cout << endl;
	//cout << bst1.Find(1)->_key << "  ";
	//cout << bst1.Find(5)->_key << "  ";
	//cout << bst1.Find(9)->_key << "  ";
	//cout << bst1.Find_R(1)->_key << "  ";
	//cout << bst1.Find_R(5)->_key << "  ";
	//cout << bst1.Find_R(9)->_key << "  ";
	//cout << endl;
	bst1.Remove_R(5);
	bst1.Remove_R(2);
	bst1.Remove_R(8);
	for (int i = 0; i < 10; ++i)
	{
		bst1.Remove_R(a[i]);
	}
	bst1.InOrder();
	bst1.Remove(5);
	bst1.Remove(2);
	bst1.Remove(8);
	for (int i = 0; i < 10; ++i)
	{
		bst1.Remove(a[i]);
	}
	bst1.InOrder();
}