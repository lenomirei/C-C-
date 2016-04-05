#pragma once
#include<iostream>
#include<cassert>
#define SIZE 100
using namespace std;

//����ͬһ�࣬������ż�±���ʵ��һ������ʵ������ջ


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
			//ûʲô������realloc���ٿռ��أ�
			//��ΪT������������Զ������ͻ�����string���͵Ļ���C���Ժ���realloc���������Щ��Ĺ��캯������ɴ���
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