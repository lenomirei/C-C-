#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class T>
struct Less
{
	bool  operator()(const T& l,const T& r)
	{
		return l < r;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& l ,const T& r)
	{
		return l > r;
	}
};





template<class T, class Compare = Less<T>>
class Heap
{
public:
	Heap()
	{

	}
	Heap(vector<T> a)
		:array(a)
	{
		for (int i = (array.size() - 2) / 2; i >=0 ; --i)
		{
			AdjustDown(i);
		}
	}
	Heap(T *a, size_t size)
	{
		for (int i = 0; i < size; ++i)
		{
			array.push_back(a[i]);
		}
		for (int i = (array.size() - 2) / 2; i >= 0; --i)
		{
			AdjustDown(i);
		}
	}
	~Heap()
	{
		
	}
	void Push(T x)
	{
		array.push_back(x);
		AdjustUp(array.size()-1);
	}
	void Pop()
	{
		swap(array.front(), array.back());
		array.pop_back();
		AdjustDown(0);
	}
	void AdjustDown(int root)
	{
		int child = root * 2 + 1;
		while (child < array.size())
		{
			if (child + 1 < array.size() && Compare()(array[child + 1], array[child]))
			{
				child++;
			}
			if (Compare(array[root], array[child]))
			{
				swap(array[root], array[child]);
				root = child;
				child = root * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
	void AdjustUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (Compare()(array[child], array[parent]))
			{
				swap(array[child], array[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
	void Print()
	{
		for (int i = 0; i < array.size(); ++i)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
	int Size()
	{
		return array.size();
	}
protected:
	vector<T> array;
};


void TestHeap()
{
	Heap<int> hp;
	int a[10] = { 5,3,6,2,1,7,8,9,4,0 };
	for (int i = 0; i < 10; ++i)
	{
		hp.Push(a[i]);
	}
	hp.Print();
}