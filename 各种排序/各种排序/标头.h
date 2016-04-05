#pragma once
#include<iostream>
#include<cassert>
using namespace std;



void InsertSort(int *a, size_t size)
{
	assert(a);
	for (int i = 1; i < size; ++i)
	{
		int index = i;
		int tmp = a[index];
		int end = index - 1;
		while (end >= 0 && a[end]>tmp)
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int *a,size_t size)
{
	assert(a);
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; ++i)
		{
			int index = i;
			int tmp = a[index];
			int end = index - gap;
			while (end >= 0 && a[end]>a[index])
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}
void SelectSort(int *a,size_t size )
{
	assert(a);
	int min;
	int max;
	for (int i = 0; i<  size; i++)
	{
		min = i;
		max =   size - 1 - i;
		for (int j = i + 1; j<  size - i; j++)
		{
			if (  a[min]>  a[j])
			{
				min = j;
			}
			if (  a[max]<  a[j])
			{
				max = j;
			}
		}
		swap(a[i], a[min]);
		swap(a[size - 1 - i], a[max]);
	}
}




void AdjustDown(int *a, size_t size, int root)
{
	assert(a);
	int child = root * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child]>a[root])
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


void HeapSort(int *a, size_t size)
{
	assert(a);
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, size, i);
	}
	for (int i = size - 1; i >= 0; --i)
	{
		swap(a[0], a[i]);
		AdjustDown(a, i, 0);
	}
}


void QuickSort(int *a, size_t size)
{
	assert(a);
	if (size <= 1)
	{
		return;
	}
	int start = 0;
	int end = size - 1;
	int value = a[0];
	while (start < end)
	{
		for (; start < end; end--)
		{
			if (a[end] < value)
			{
				a[start++] = a[end];
				break;
			}
		}
		for (; start < end; start++)
		{
			if (a[start]>value)
			{
				a[end--] = a[start];
				break;
			}
		}
	}
	a[start] = value;
	QuickSort(a, start);
	QuickSort(a + start + 1, size - start - 1);
}

void Printa(int *a, size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}


int a[10] = { 6,7,8,9,0,1,2,3,4,5 };

void TestInsertSort()
{
	Printa(a, 10);
	InsertSort(a, 10);
	Printa(a, 10);
}
void TestSelectSort()
{
	Printa(a, 10);
	SelectSort(a, 10);
	Printa(a, 10);
}
void TestHeapSort()
{
	Printa(a, 10);
	HeapSort(a, 10);
	Printa(a, 10);
}
void TestQuickSort()
{
	Printa(a, 10);
	QuickSort(a, 10);
	Printa(a, 10);
}
void TestShellSort()
{
	Printa(a, 10);
	ShellSort(a, 10);
	Printa(a, 10);
}