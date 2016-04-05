#pragma once
#include<iostream>
#include<vector>
using namespace std;



//template<class T, class Compare=less<T>>
//template<class T>
//struct Less
//{
//	bool operator()
//	{
//
//	}
//};



template<class T>
class Heap
{
public:
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
		AdjustUp((array.size()-2)/2);
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
			if (child + 1 < array.size() && array[child + 1] < array[child])
			{
				child++;
			}
			if (array[root] > array[child])
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
	void AdjustUp(int root)
	{
		int child = root * 2 + 1;
		while (child != 0)
		{
			if (child + 1 < array.size() && array[child + 1] < array[child])
			{
				child++;
			}
			if (array[root] > array[child])
			{
				swap(array[root], array[child]);
				child = root;
				root = (child - 1) / 2;
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


