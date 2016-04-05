#include <iostream>
using namespace std;

void test_alloc1 ()
{
	int* p4 = new int;         // 动态分配4个字节（1个int）的空间单个数据
	int* p5 = new int(3);      // 动态分配4个字节（1个int）的空间并初始化为3
	int* p6 = new int[3];      // 动态分配12个字节（3个int）的空间

	delete p4 ;
	delete p5 ;
	delete[] p6 ;
}

void Test1()
{
	char a2 [] = "abcd";
	char* a3 = "abcd";

	cout<<sizeof(a2)<<endl; // 5
	cout<<strlen(a2)<<endl;	// 4
	cout<<sizeof(a3)<<endl; // 4
	cout<<strlen(a3)<<endl; // 4

	a2[0] = 'x';
	a3[0] = 'x';
}

class Array
{
public :
	Array (size_t size = 10)
		: _a(0)
	{
		cout<<"Array(size_t size)" <<endl;

		if (size > 0)
		{
			_a = new int[size];
		}
	}

	~ Array()
	{
		cout<<"~Array()" <<endl;

		if (_a )
		{
			delete[] _a ;
			_a = 0;
		}
	}
private :
	int*	_a ;
};

class AA
{
	int _a;
};

template<class T>
void f(T* p)
{
	p->~T(); // ~int();
}

void Test2()
{
	//Array* p1 = new Array;
	//Array* p2 = (Array*)malloc(sizeof(Array));
	//delete p1;
	//free(p2);

	//Array* p3 = new Array[10];
	//delete[] p3;

	//Array* p1 = new Array(20);
	//delete p1;

	////int* p2= (int*)operator new(sizeof(int)*2);

	Array* p1 = new Array[10]; // 44
	int* p2 = new int[10];	   // 40
	AA* p3= new AA[10];		// 44? 40

	int* p4 = (int*) operator new(sizeof(int));
	new(p4) int(4);

	int i = int(1);
	//i.~int();
	f(&i);

	AA aa();
}

int main()
{
	Test2();
	return 0;
}