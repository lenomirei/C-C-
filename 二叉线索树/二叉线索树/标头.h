#pragma once
#include<iostream>
#include<stack>
using namespace std;



enum PointerTag
{
	THREAD,
	LINK
};

template<class T>
struct BinaryTreeNode_Th
{
	T _data;
	BinaryTreeNode_Th *_left;
	BinaryTreeNode_Th *_right;
	PointerTag _leftTag;
	PointerTag _rightTag;
	BinaryTreeNode_Th(T x)
		:_data(x)
		,_left(NULL)
		,_right(NULL)
		,_leftTag(LINK)
		,_rightTag(LINK)
	{

	}
};

template<class T>
class BinaryTree_Th
{
public:
	BinaryTree_Th(T *array, size_t size)
	{
		int index = 0;
		_root = _CreateBinaryTree_Th(array, size, index);
	}
	void InOrderThread()
	{
		//利用递归实现的中序线索化
		BinaryTreeNode_Th<T>* prev = NULL;
		_InOrderThread(_root, prev);
	}
	void InOrder()
	{
		BinaryTreeNode_Th<T> *cur = _root;
		while (cur)
		{
			while (cur->_left != NULL && cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			while (cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}
			cur = cur->_right;
		}
		cout << endl;
	}

	void PrevOrderThread()
	{
		BinaryTreeNode_Th<T> *prev = NULL;
		_PrevOrderThread(_root, prev);
	}

	void PrevOrder()
	{
		BinaryTreeNode_Th<T> *cur = _root;
		while(cur)
		{
			while (cur && cur->_leftTag!= THREAD)
			{
				cout << cur->_data << " ";
				cur = cur->_left;
			}
			while (cur)
			{
				cout << cur->_data << " ";
				cur = cur->_right;
			}
		}
		cout << endl;
	}
	void PostOrderThread()
	{
		BinaryTreeNode_Th<T> *prev = NULL;
		_PostOrderThread(_root,prev);
	}
	void PostOrder()
	{
		stack<T> s;
		BinaryTreeNode_Th<T> *cur = _root;
		while (cur)
		{
			while (cur && cur->_rightTag != THREAD)
			{
				s.push(cur->_data);
				cur = cur->_right;
			}
			
			s.push(cur->_data);
			cur = cur->_left;
			
		}
		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
protected:
	void _PostOrderThread(BinaryTreeNode_Th<T> *cur, BinaryTreeNode_Th<T> *&prev)
	{
		if (cur == NULL)
		{
			return;
		}
		if (cur->_leftTag == LINK)
		{
			_PostOrderThread(cur->_left, prev);
		}
		if (cur->_rightTag == LINK)
		{
			_PostOrderThread(cur->_right, prev);
		}
		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}
		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		prev = cur;
	}
	void _InOrderThread(BinaryTreeNode_Th<T> *cur,BinaryTreeNode_Th<T> *&prev)
	{
		if (NULL == cur)
		{
			return;
		}
		_InOrderThread(cur->_left,prev);

		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}
		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		prev = cur;

		_InOrderThread(cur->_right,prev);
	}
	void _PrevOrderThread(BinaryTreeNode_Th<T> *cur, BinaryTreeNode_Th<T> *&prev)
	{
		if (NULL == cur)
		{
			return;
		}
		if (NULL == cur->_left)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}
		if (prev && NULL == prev->_right)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		prev = cur;


		if (cur->_leftTag == LINK)
		{
			_PrevOrderThread(cur->_left,prev);
		}
		if (cur->_rightTag == LINK)
		{
			_PrevOrderThread(cur->_right,prev);
		}
	}
	BinaryTreeNode_Th<T>* _CreateBinaryTree_Th(T *array, size_t size, int &index)
	{
		BinaryTreeNode_Th<T>  *newroot = NULL;
		if (array[index] != '#' && index < size)
		{
			newroot = new BinaryTreeNode_Th<T>(array[index]);
			newroot->_left = _CreateBinaryTree_Th(array, size, ++index);
			newroot->_right = _CreateBinaryTree_Th(array, size, ++index);
		}
		return newroot;
	}

protected:
	BinaryTreeNode_Th<T> *_root;
};