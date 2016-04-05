#pragma once
#include<iostream>
#include<cassert>
using namespace std;




template<class T>
struct QueueNode
{
	T data;
	QueueNode<T>* next;
	QueueNode(T x)
		:data(x)
		,next(NULL)
	{

	}
};

template<class T>
class Queue
{
public:
	Queue()
		:head(NULL)
		,tail(NULL)
	{
	}
	Queue(Queue &q)
	{
		head = new QueueNode<T>(q.head->data);
		tail = head;
		QueueNode<T> *tmp = q.head->next;
		while (tmp)
		{
			tail->next = new QueueNode<T>(tmp->data);
			tail = tail->next;
			tmp = tmp->next;
		}
	}
	~Queue()
	{
		if (head)
		{
			QueueNode<T> *del = head;
			while (head)
			{
				del = head;
				head = head->next;
				delete del;
			}
		}
	}
	void Pop()
	{
		assert(head);//忘记了没有数据的时候无法删除的情况
		if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		QueueNode<T> *tmp = head;
		head = head->next;
		delete tmp;
	}
	void Push(T x)
	{
		if (head)
		{
			QueueNode<T>* tmp = new QueueNode<T>(x);
			tail->next = tmp;
			tail = tmp;
		}
		else
		{
			head = new QueueNode<T>(x);
			tail = head;
		}
	}
	bool Empty()
	{
		if (head)
		{
			return false;
		}
		return true;
	}
	int Size()
	{
		int count = 0;
		QueueNode<T> *tmp = head;
		while (tmp)
		{
			count++;
			tmp = tmp->next;
		}
		return count;
	}
	T& Front()
	{
		return head->data;
	}

	T& Back()
	{
		return tail->data;
	}
protected:
	QueueNode<T>* head;
	QueueNode<T>* tail;
};