#pragma once
#include<iostream>
#include<cassert>
#include<stack>
using namespace std;


int GetMidIndex(int *a, int left, int right)
{
	assert(a);
	int mid = left + (right - left) / 2;
	if (a[left] < a[right])
	{
		if (a[mid] < a[left])
		{
			return left;
		}
		else if (a[mid] < a[right])
		{
			return mid;
		}
		else
			return right;
	}
	else
	{
		if (a[mid] < a[right])
		{
			return right;
		}
		else if (a[mid] < a[left])
		{
			return mid;
		}
		else
			return left;
	}
}

int PartionSort2(int *a,int left,int right)
{
	int key = a[right];
	int cur = left;
	int prev = left - 1;
	while (cur < right)
	{
		if (a[cur] < key && prev++ != cur)
		{
			swap(a[prev], a[cur]);
		}
		cur++;
	}
	swap(a[prev], a[cur]);
	return prev;
}





int PartionSort(int *a,int left,int right)
{
	int MidIndex = GetMidIndex(a, left, right);
	swap(a[MidIndex], a[right]);
	int key = a[right];
	int begin = left;
	int end = right - 1;
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		if (begin < end)
		{
			swap(a[begin], a[end]);
		}
	}
	if (a[begin] > key)
	{
		swap(a[begin], a[right]);
		return begin;
	}
	return right;
}

void QuickSort(int *a,int left,int right)
{
	assert(a);
	if (right - left < 1)
	{
		return;
	}
	int boundary = PartionSort(a,left,right);
	QuickSort(a, left, boundary-1);
	QuickSort(a, boundary + 1, right);

}
void TestQuickSort()
{
	int a[10] = { 7,8,3,0,5,5,1,2,9,4 };
	QuickSort(a, 0, 9);

}
void MergeSelection(int *a, int *tmp, int begin1, int end1, int begin2, int end2)
{
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
}


void MergeSort(int *a ,int *tmp,int left,int right)
{
	int mid = left + (right - left) / 2;
	if (left < right)
	{

		MergeSort(a, tmp, left, mid);
		MergeSort(a, tmp, mid + 1, right);
		MergeSelection(a, tmp, left, mid, mid + 1, right);

		memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
	}
}

void TestMergeSort()
{
	int a[10] = { 7,8,3,0,5,5,1,2,9,4 };
	int tmp[10] = { 0 };
	MergeSort(a, tmp, 0, 9);
}



struct testnode
{
	int _left;
	int _right;
	testnode(int left,int right)
		:_left(left)
		,_right(right)
	{

	}
};

void QuickSort_NonR(int *a)
{
	stack<testnode> s;
	s.push(testnode(0, 9));
	while (!s.empty())
	{
		testnode top = s.top();
		s.pop();
		int MidIndex = GetMidIndex(a, top._left, top._right);
		swap(a[MidIndex], a[top._right]);
		int key = a[top._right];
		int begin = top._left;
		int end =top._right - 1;
		while (begin < end)
		{
			while (begin < end && a[begin] <= key)
			{
				++begin;
			}
			while (begin < end && a[end] >= key)
			{
				--end;
			}
			if (begin < end)
			{
				swap(a[begin], a[end]);
			}
		}
		if (a[begin] > key)
		{
			swap(a[begin], a[top._right]);
			s.push(testnode(top._left, begin));
			s.push(testnode(begin + 1, top._right));
		}
	}
}


void TestQuickSort_Non()
{
	int a[10] = { 7,8,3,0,5,5,1,2,9,4 };
	QuickSort(a, 0, 9);

}

//#include<vector>
//void MergeSort_NonR(int *a,int *tmp,size_t size)
//{
//
//	vector<int> gaparray;
//	int c = 2;
//	while (size / c)
//	{
//		gaparray.push_back(size / c);
//		c *= 2;
//	}
//	int gap = 0;//就是小区间的长度，i设置为两个小区间开始的位置，加上两个gap就可以得到两个小区间结束的位置
//	while (!gaparray.empty())
//	{
//		for (int i = 0; i + 2 * gap < size; ++i)
//		{
//			MergeSelection(a, tmp, i, i + gap, i + gap + 1, i + 2 * gap + 1);
//			memcpy(a + i, tmp + i, sizeof(int)*(i + 2 * gap + 1 - i + 1));
//		}
//		
//		gap = gaparray.back();
//		gaparray.pop_back();
//	}
//}
//
//
//void TestMergeSort_NonR()
//{
//	int a[10] = { 7,8,3,0,5,5,1,2,9,4 };
//	int tmp[10];
//	MergeSort_NonR(a,tmp, 10);
//}

int a[10] = { 7,8,3,0,5,5,1,2,9,4 };
int tmp[10];
void MergeSort_NonR(int *a1 ,int *tmp1,size_t size)
{
	int i;
	int gap = 2;
	while (gap < size)
	{
		for (i = 0; i + gap - 1< size;i+=gap)
		{
			MergeSelection(a, tmp, i, i + gap / 2 - 1, i + gap / 2, i + gap - 1);
			memcpy(a + i, tmp + i, sizeof(int)*(gap));

		}
		MergeSelection(a, tmp, i - gap, i - 1, i, size - 1);
		memcpy(a + i - gap, tmp + i - gap, sizeof(int)*(size - (i - gap)));
		gap *= 2;
	}
}


void TestMergeSort_NonR()
{
	
	MergeSort_NonR(a, tmp, 10);
}