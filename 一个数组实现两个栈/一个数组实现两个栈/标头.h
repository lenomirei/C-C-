#pragma once
#include<iostream>
#include<cassert>
#define SIZE 100
using namespace std;

//采用同一侧，但是奇偶下标来实现一个数组实现两个栈


template<class T>
class Stack
{
public:
	Stack()
		:_array(NULL)
		,capacity(0)
	{
		memset(size, 0, sizeof(size_t) * 2);
	}
	~Stack()
	{}
	void Push(T x,int n)
	{
		CheckCapacity();
		_array[size[n - 1] * n] = x;
		size[n - 1]++;
	}
	void Pop(int n)
	{
		assert(size[n - 1]);
		size[n - 1]--;
	}
	T& Top(int n)
	{
		assert(size[n - 1]);
		return _array[size[n - 1] - 1];
	}
	size_t Size(int n)
	{
		return size[n-1];
	}
protected:
	void CheckCapacity()
	{
		if (size[0]+size[1] >= capacity)
		{
			//没什么不采用realloc开辟空间呢？
			//因为T的类型如果是自定义类型或者是string类型的话，C语言函数realloc不会调用这些类的构造函数会造成错误
			T* tmp = new T[capacity + SIZE];
			for (size_t i = 0; i < capacity; ++i)
			{
				tmp[i] = _array[i];
			}
			_array = tmp;
			capacity += SIZE;
		}
	}
protected:
	T *_array;
	size_t size[2];
	size_t capacity;
};