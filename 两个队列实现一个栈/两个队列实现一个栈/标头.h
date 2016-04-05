#pragma once
#include<iostream>
#include<cassert>
#include<queue>
using namespace std;

template<class T>
class Stack
{
public:
	Stack()
	{
	}
	~Stack()
	{

	}
	void Push(T x)
	{
		if (q1.size() == 0)
		{
			q2.push(x);
		}
		else
		{
			q1.push(x);
		}
	}
	void Pop()
	{
		assert(Size());
		if (q1.size() == 0)
		{
			for (int i = 0; i < Size() - 1; ++i)
			{
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
		}
		else
		{
			for (int i = 0; i < Size() - 1; ++i)
			{
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
		}
	}
	T Top()
	{
		if (q1.size() == 0)
		{
			return q2.back();
		}
		else
		{
			return q1.back();
		}
	}
	size_t Size()
	{
		return q1.size() + q2.size();
	}
protected:
	queue<T> q1;
	queue<T> q2;
};
