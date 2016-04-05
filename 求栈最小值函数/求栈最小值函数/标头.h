#pragma once
#include<iostream>
#include<cassert>
#include<string>
using namespace std;


template<class T, int n>
class Stack
{
public:
	Stack()
		:array(NULL)
		, size(0)
		, capacity(0)
	{}
	Stack(T* a)
		:array(new T[sizeof(a) / sizeof(T)])
		, size(sizeof(a) / sizeof(T))
		, capacity(size)
	{
		memcpy(array, a, size);
	}
	//��ǳ��������
	Stack(Stack<T, n>& s)
		:array(NULL)
		: size(s.size)
		, capacity(s.capacity)
	{
		Stack tmp(s.array);
		swap(tmp.array, array);
	}
	~Stack()
	{
		if (array)
		{
			delete[] array;
			array = NULL;
		}
	}


	void Pop()
	{
		assert(size > 0);
		size--;
	}
	void Push(T x)
	{
		CheckCapacity();
		if (0 == size)
		{
			array[0] = x;
			array[1] = x;
		}
		else
		{
			if (x < array[2 * size - 2])
			{
				array[2 * (size)] = x;
			}
			else
			{
				array[2 * (size)] = array[2 * size - 2];
			}
			array[2*size+1] = x;
		}
		size++;
	}
	bool Empty()
	{
		if (0 == size)
		{
			return true;
		}
		return false;
	}
	T& Top()
	{
		assert(array);
		return array[2*size - 1];

	}
	size_t Size()
	{
		return size;
	}
	T Min()
	{
		return array[2 * size - 2];
	}





protected:
	void CheckCapacity()
	{
		if (size >= capacity)
		{
			//ûʲô������realloc���ٿռ��أ�
			//��ΪT������������Զ������ͻ�����string���͵Ļ���C���Ժ���realloc���������Щ��Ĺ��캯������ɴ���
			T* tmp = new T[capacity + n];
			for (size_t i = 0; i < size; ++i)
			{
				tmp[i] = array[i];
			}
			array = tmp;
			capacity += n;
		}
	}

protected:
	T *array;
	size_t size;
	size_t capacity;
};