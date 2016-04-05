//#include"БъЭЗ.h"
//
//
//void  test()
//{
//	vector<int> a = {15,61,12,5,3,8,10};
//	Heap<int> h1(a);
//	h1.Print();
//	h1.Push(14);
//	h1.Print();
//	h1.Pop();
//	h1.Print();
//}
//
//
//
//int main()
//{
//	test();
//	return 0;
//}




#include<iostream>
using namespace std;


template<class T>
void HeapSort(T *a, size_t size)
{
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		AdjustDown<T>(a, size, i);
	}
	size_t _size = size;
	while(_size > 0)
	{
		swap(a[0], a[_size - 1]);
		_size--;
		AdjustDown<T>(a, _size, 0);
	}
}

template < class T >
void AdjustDown(T *a, size_t size, int root)
{
	int child = root*2+1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[root])
		{
			swap(a[child], a[root]);
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	int array[10] = { 5,3,6,2,1,7,8,9,4,0 };
	HeapSort<int>(array, 10);
	for (int i = 0; i < 10;++i)
	{
		cout<<array[i]<<"  ";
	}
	return 0;
}