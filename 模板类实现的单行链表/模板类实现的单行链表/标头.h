#pragma once
#include<iostream>
using namespace std;
template<class T>
struct ListNode
{
	T _data;
	ListNode* _next;
	ListNode(T x)
		:_data(x)
		,_next(NULL)
	{
		
	}
};
template<class T>
class List
{
public:
	List()
		:_head(NULL)
		, _end(_head)
	{}
	List(List& l)
		:_head(NULL)
		,_end(_head)
	{
		ListNode<T> *cur = l._head;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	~List()
	{

	}
	void PushBack(T x)//要分好几种情况讨论？1.链表中没有数据的时候2.链表中有1个货多个数据的时候
	{
		if (NULL == _head)
		{
			_head = new ListNode<T>(x);
			_end = _head;
		}
		else
		{
			ListNode<T> *tmp = new ListNode<T>(x);
			_end->_next = tmp;
			_end = tmp;
		}
	}
	void PrintList()
	{
		ListNode<T> *cur = _head;
		while (cur)
		{
			cout << cur->_data << "->";
			cur = cur->_next;
			
		}
		cout << "NULL" << endl;
	}

	void Destory()
	{
		ListNode<T> *cur = _head;
		ListNode<T> *del = _head;
		while (cur)
		{
			cur = cur->_next;
			delete del;
			del = cur;
		}
	}


	List& operator=(List& l)
	{
		if (*this != l)
		{
			Destory();
			ListNode<T> *cur = l._head;
			while (cur)
			{
				PushBack(cur->_data);
			}
		}
		return *this;
	}

private:
	ListNode<T> *_head;
	ListNode<T> *_end;
};