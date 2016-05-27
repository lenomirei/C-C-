#pragma once
#include<iostream>
using namespace std;

template<class T>
class UnionFindSet
{
public:
	UnionFindSet(size_t size)
		:_set(new T[size])
		,_size(size)
	{

	}
	~UnionFindSet()
	{
		delete[] _set;
	}
	void Combine(int root1,int root2)
	{
		if (root1 >= 0)
		{
			root1 = FindRoot(root1);
		}
		if (root2 >= 0)
		{
			root2 = FindRoot(root2);
		}
		set[root1] += set[root2];
		set[root2] = root1;
	}


	void FindRoot(int child)
	{
		while (_set[child] >= 0)
		{
			child = set[child];
		}
		return child;
	}
protected:
	T *_set;
	size_t _size;
};