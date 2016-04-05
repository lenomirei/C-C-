#pragma once
#include<iostream>
#include<cassert>
using namespace std;



struct FalseType
{};
struct TrueType
{};

template<class _Tp>
class TypeTraits
{
public:
	typedef FalseType IsPODType;
};


template<>
class TypeTraits<int>
{
public:
	typedef TrueType IsPODType;
};









template<class T,int n>
class Stack
{
public:


	void Copy(T *Dst,T *Src,size_t s, FalseType)
	{
		memcpy(Dst, Src, s);
	}

	void Copy(T *Dst, T *Src, size_t s, TrueType)
	{
		for (int i = 0; i < s; i++)
		{
			Dst[i] = Src[i];
		}
	}
	



	Stack()
		:array(NULL)
		, size(0)
		, capacity(0)
	{}
	//Stack(T* a)
	//	:array(a)
	//	,size(sizeof(a)/sizeof(T))
	//	,capacity(size)e
	//{

	//}这个函数是有错误的
	//深浅拷贝问题
	Stack(const Stack<T,n>& s)
		:array(NULL)
		:size(s.size)
		,capacity(s.capacity)
	{
		Stack tmp(s.array);
		swap(tmp.array, array);
	}
	~Stack()
	{
		if (array)
		{
			delete[] array;
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
		array[size++] = x;
	}
	bool Empty()
	{
		if (0 == size)
		{
			return true;
		}
		return false;
		//return size==0;
	}
	T& Top()
	{
		return array[size-1];
	}
	size_t Size()
	{
		return size;
	}

protected:
	void CheckCapacity()
	{
		if (size >= capacity)
		{
			//没什么不采用realloc开辟空间呢？
			//因为T的类型如果是自定义类型或者是string类型的话，C语言函数realloc不会调用这些类的构造函数会造成错误
			T* tmp = new T[capacity + n];
			/*memcpy(tmp, array, size);*///不用memcpy你懂的，例如string类
			//for (size_t i = 0; i < size; ++i)
			//{
			//	tmp[i] = array[i];
			//}
			Copy(tmp, array, size,TypeTraits<T>::IsPODType());
			//但是使用for循环赋值速度又太慢了,这个时候就要用到类型萃取
			//模板特化当然也是可以的哦
			capacity += n;
			delete[] array;
			array = tmp;
		}
	}
protected:
	T *array;
	size_t size;
	size_t capacity;
};