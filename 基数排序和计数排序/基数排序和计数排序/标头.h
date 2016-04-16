#pragma once
#include<iostream>
using namespace std;



void CountSort(int *a , size_t size)
{
	int max = a[0], min = a[0];
	for (int i =1; i < size; ++i)
	{
		if (max < a[i])
		{
			max = a[i];
		}
		if (min > a[i])
		{
			min = a[i];
		}
	}
	int index = 0;
	int *CountArray = new int[max - min + 1];
	memset(CountArray, 0, sizeof(int)*(max - min + 1));
	for (int i = 0; i < size; ++i)
	{
		CountArray[a[i] - min]++;
	}
	for (int i = 0; i < max - min + 1; ++i)
	{
		for (int j = 0; j < CountArray[i]; ++j)
		{
			a[index++] = i + min;
		}
	}
}

void TestCountSort()
{
	int a[10] = { 7,8,3,0,5,5,1,2,9,4 };
	CountSort(a, 10);
}


int GetMaxDigit(int *a,size_t size)
{
	int digit = 1;
	int max = 10;
	for (int i = 0; i < size; ++i)
	{
		while (a[i] >= max)
		{
			digit++;
			max *= 10;
		}
	}
	return digit;
}

//一共需要几个数组呢？一个count,一个start还有一个收集用的暂存数组？最后拷贝回去就可以了！
void DigitSort(int *a, size_t size)
{
	int MaxDigit = GetMaxDigit(a, size);
	int curDigit = 1;
	int digit = 0;
	int Count[10];
	int Start[10];
	int *Bucket = new int[size];
	while (digit < MaxDigit)
	{
		memset(Count, 0, sizeof(int) * 10);
		memset(Start, 0, sizeof(int) * 10);
		for (int i = 0; i < size; ++i)
		{
			int num = a[i] / curDigit % 10;
			Count[num]++;
		}
		Start[0] = 0;
		for (int i = 1; i < 10; ++i)
		{
			Start[i] = Start[i - 1] + Count[i - 1];
		}
		for (int i = 0; i < size; ++i)
		{
			int num = a[i] / curDigit % 10;
			Bucket[Start[num]++] = a[i];
		}
		memcpy(a, Bucket, sizeof(int)*size);
		digit++;
		curDigit *= 10;
	}
}

void TestDigitSort()
{
	int a[10] = { 7,8,3,0,5,5,1,2,9,4 };
	DigitSort(a, 10);
}