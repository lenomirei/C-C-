//
//#include<iostream>
//using namespace std;
//
//
//class A 
//{
//public:
//	virtual void func()
//	{
//	}
//	int _a;
//};
//class B :virtual public A
//{
//public:
//	void func()
//	{
//	}
//	int _b;
//};
//class C :virtual public A
//{
//public:
//	void func()
//	{
//	}
//	int _c;
//};
//class D :public B,public C
//{
//public:
//	void func()
//	{
//	}
//	int _d;
//};
//
//
//
//
//int main()
//{
//	D d;
//	B b;
//	b._b = 1;
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	cout << sizeof(C) << endl;
//	cout << sizeof(D) << endl;
//	return 0;
//}
//
//
//
//
//
//
//
////#include<iostream>
////using namespace std;
////
////
////
////class A
////{
////
////public:
////	A()
////	{
////		cout << "A:构造函数" << endl;
////	}
////	A(const A& a)
////	{
////		cout << "A:拷贝构造函数" << endl;
////	}
////	//A operator=(const A& a)
////	//{
////	//	cout << "A:赋值运算符重载函数" << endl;
////	//	return a;
////	//}
////};
////
////A f(A a)
////{
////	return a;
////}
////
////
////
////
////void Test1()
////{
////	A a1;
////	a1 = f(a1);//两次拷贝构造
////	cout << "-----------------------" << endl;
////}
////void Test2()
////{
////	A a1;
////	A a2 = f(a1);//三次拷贝构造
////	cout << "-----------------------" << endl;
////}
////void Test3()
////{
////	A a1;
////	A a2 = f(f(a1));//三次拷贝构造
////	cout << "-----------------------" << endl;
////}
////
////
////int main()
////{
////	Test1();
////	Test2();
////	Test3();
////	return 0;
////}

#include<iostream>
using namespace std;

void QuickSort(int *a,size_t length)
{
	if (length < 1)
	{
		return;
	}
	int value = a[0];
	int start = 0;
	int end = length - 1;

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
	QuickSort(a + start + 1, length - start - 1);
}


void MergeSelection(int *a, int begin1, int end1, int begin2, int end2, int *tmp)
{
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
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



void MergeSort(int *a,int left,int right,int *tmp)
{
	int mid = left + (right - left) / 2;

	if (left < right)
	{
		MergeSort(a,left,mid,tmp);
		MergeSort(a,mid+1,right,tmp);
		MergeSelection(a,left,mid,mid+1,right,tmp);
		memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
	}
	
}






int main()
{
	int tmp[10] = {0};
	int a[] = { 6,7,8,9,0,1,2,3,4,5 };
//	QuickSort(a, 10);
	MergeSort(a, 0,9,tmp);

	return 0;
}