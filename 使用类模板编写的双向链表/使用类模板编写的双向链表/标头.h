#pragma once
#include<iostream>
using namespace std;


template<class T>


struct ListNode
{
	T _data;
	ListNode *_next;
	ListNode *_prev;
	ListNode(T x)
		:_data(x)
		,_next(NULL)
		,_prev(NULL)
	{
	}
};
template<class T>
class SXList
{
public:
	SXList()
		:_head(NULL)
		,_end(_head)
	{

	}
	SXList(SXList& l)
		:_head(NULL)
		,_end(_head)
	{

	}
	void PushBack(T x)//分为两种情况1.链表中无数据2.链表中有一个或者多个数据
	{
		if (NULL==_head)
		{
			_head = new ListNode<T>(x);
			_end = _head;
		}
		else
		{
			ListNode<T>* tmp = new ListNode<T>(x);
			tmp->_prev = _end;
			_end->_next = tmp;
			_end = tmp;
		}
	}
	~SXList()
	{

	}

	void PrintList()
	{
		ListNode<T>* cur = _head;
		while (cur)
		{
			cout << cur->_data << "<->";
			cur = cur->_next;
		}
		cout << "NULL" << endl;
	}


	void swap(ListNode<T>* gai)
	{
		ListNode<T>* tmp;
		tmp = gai->_next;
		gai->_next = gai->_prev;
		gai->_prev = tmp;
	}
	void Reverse()
	{
		ListNode<T>* tmp;
		ListNode<T>* cur = _head;
		ListNode<T>* gai = _head;
		while (cur)
		{
			cur = cur->_next;
			swap(gai);
			gai = cur;
		}

		tmp = _head;
		_head = _end;
		_end = tmp;
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

	SXList& operator=(SXList &s)
	{
		Destory();
		ListNode<T> *cur = s._head;
		while (cur)
		{
			PushBack(cur->_data);
		}
	}
private:
	ListNode<T> *_head;
	ListNode<T> *_end;
};