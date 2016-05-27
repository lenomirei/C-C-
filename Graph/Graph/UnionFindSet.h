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
		for (int i = 0; i < size; ++i)
		{
			_set[i] = -1;
		}
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
		_set[root1] += _set[root2];
		_set[root2] = root1;
	}


	int FindRoot(int child)
	{
		while (_set[child] >= 0)
		{
			child = _set[child];
		}
		return child;
	}
protected:
	T *_set;
	size_t _size;
};