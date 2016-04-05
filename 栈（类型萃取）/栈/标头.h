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

	//}����������д����
	//��ǳ��������
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
			//ûʲô������realloc���ٿռ��أ�
			//��ΪT������������Զ������ͻ�����string���͵Ļ���C���Ժ���realloc���������Щ��Ĺ��캯������ɴ���
			T* tmp = new T[capacity + n];
			/*memcpy(tmp, array, size);*///����memcpy�㶮�ģ�����string��
			//for (size_t i = 0; i < size; ++i)
			//{
			//	tmp[i] = array[i];
			//}
			Copy(tmp, array, size,TypeTraits<T>::IsPODType());
			//����ʹ��forѭ����ֵ�ٶ���̫����,���ʱ���Ҫ�õ�������ȡ
			//ģ���ػ���ȻҲ�ǿ��Ե�Ŷ
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