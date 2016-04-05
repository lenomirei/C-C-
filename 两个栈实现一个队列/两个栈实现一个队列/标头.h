#pragma once
#include<iostream>
#include<cassert>
#include<stack>
using namespace std;

template<class T>
class Queue
{
public:
	Queue()
	{

	}
	~Queue()
	{

	}
	void Push(T x)
	{
		if (s2.size() == 0)
		{
			s1.push(x);
		}
		else
		{
			while (s1.size() != 0)
			{
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(x);
		}
	}
	void Pop()
	{
		assert(Size());
		if (s2.size() == 0)
		{
			while (s1.size())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		s2.pop();
	}
	T Top()
	{
		if (s2.size() == 0)
		{
			while (s1.size())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}
	size_t Size()
	{
		return s1.size() + s2.size();
	}
protected:
	stack<T> s1;
	stack<T> s2;
};