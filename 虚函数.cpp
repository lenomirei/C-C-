////#include <iostream>
////using namespace std;
////
////class Base
////{
////public :
////	virtual void func1()
////	{
////		cout<<"Base::func1" <<endl;
////	}
////
////	virtual void func2()
////	{
////		cout<<"Base::func2" <<endl;
////	}
////
////private :
////	int a ;
////};
////
////class Derive :public Base
////{
////public :
////	virtual void func1()
////	{
////		cout<<"Derive::func1" <<endl;
////	}
////
////	virtual void func3()
////	{
////		cout<<"Derive::func3" <<endl;
////	}
////
////	virtual void func4() // this
////	{
////		cout<<"Derive::func4" <<endl;
////	}
////
////	//virtual void func5(int i)
////	//{
////	//	cout<<"Derive::func1" <<endl;
////	//}
////
////private :
////	int b ;
////};
////
////typedef void (*Base::FUNC) (Base*);
////
////void PrintVTable (int* VTable, Base* that)
////{
////	cout<<" 虚表地址>"<< VTable<<endl ;
////
////	for (int i = 0; VTable[i ] != 0; ++i)
////	{
////		printf(" 第%d个虚函数地址 :0X%x,->", i , VTable[i ]);
////		FUNC f = (FUNC) VTable[i ];
////		that->f();
////	}
////
////	cout<<endl ;
////}
////
////void Test1 ()
////{
////	Base b1 ;
////	Derive d1 ;
////
////	int* VTable1 = (int*)(*( int*)&b1 );
////	int* VTable2 = (int*)(*( int*)&d1 );
////
////	PrintVTable(VTable1, &b1);
////	//PrintVTable(VTable2 );
////}
////
////int main()
////{
////	Test1();
////
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//
//class Base1
//{
//public :
//	virtual void func1()
//	{
//		cout<<"Base1::func1" <<endl;
//	}
//
//	virtual void func2()
//	{
//		cout<<"Base1::func2" <<endl;
//	}
//
//private :
//	int b1 ;
//};
//
//class Base2
//{
//public :
//	virtual void func1()
//	{
//		cout<<"Base2::func1" <<endl;
//	}
//
//	virtual void func2()
//	{
//		cout<<"Base2::func2" <<endl;
//	}
//
//private :
//	int b2 ;
//};
//
//
//class Derive : public Base1, public Base2
//{
//public :
//	virtual void func1()
//	{
//		cout<<"Derive::func1" <<endl;
//	}
//
//	virtual void func3()
//	{
//		cout<<"Derive::func3" <<endl;
//	}
//
//private :
//	int d1 ;
//};
//
//typedef void (* FUNC) ();
//
//void PrintVTable (int* VTable)
//{
//	cout<<" 虚表地址>"<< VTable<<endl ;
//
//	for (int i = 0; VTable[i ] != 0; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i , VTable[i ]);
//		FUNC f = (FUNC) VTable[i ];
//		f();
//	}
//
//	cout<<endl ;
//}
//
//void Test1 ()
//{
//	Derive d1 ;
//
//	int* VTable = (int*)(*( int*)&d1);
//
//	PrintVTable(VTable );
//
//	// Base2虚函数表在对象Base1后面
//	VTable = (int *)(*((int*)&d1 + sizeof (Base1)/4));
//	PrintVTable(VTable );
//}
//
//int main()
//{
//	Test1();
//
//	return 0;
//}

#include <iostream>
using namespace std;

class Base
{
public:
	virtual void f1()
	{
		cout<<"Bsse::f1"<<endl;
	}

	virtual void f2()
	{
		cout<<"Bsse::f2"<<endl;
	}

public:
	int _b;
};

class Base1: virtual public Base
{
public:
	virtual void f1()
	{
		cout<<"Bsse1::f1"<<endl;
	}

	virtual void f3()
	{
		_b1 = 10;
		cout<<"Bsse1::f3"<<endl;
	}

	int _b1;
};

class Base2: virtual public Base
{
public:
	virtual void f1()
	{
		cout<<"Bsse2::f1"<<endl;
	}

	virtual void f4()
	{
		cout<<"Bsse2::f4"<<endl;
	}

	int _b2;
};

class Derive: public Base1, public Base2
{
public:
	virtual void f1()
	{
		_d = 10;
		cout<<"Derive::f1"<<endl;
	}

	virtual void f3()
	{
		this->_d = 10;
		cout<<"Derive::f3"<<endl;
	}

	virtual void f4()
	{
		cout<<"Derive::f4"<<endl;
	}

	virtual void f5()
	{
		cout<<"Derive::f5"<<endl;
	}
	int _d;
};


// __thiscall
// __cscall

typedef void(__thiscall*FUNC)(Derive*);

void PrintVTable (int* VTable, Derive* that)
{
	cout<<" 虚表地址>"<< VTable<<endl ;
	FUNC* VF = (FUNC*)VTable;
	for (int i = 0; VTable[i ] != 0; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i , VTable[i ]);
		FUNC f = (FUNC)VTable[i];
		f(that);
	}

	cout<<endl ;
}


void Test()
{
	Derive d;

	d.Base1::_b = 1;
	d.Base2::_b = 2;

	d._b1 = 3;
	d._b2 = 4;
	d._d = 5;

	int* vTable = (int*)(*(int*)&d);
	PrintVTable(vTable, &d);
}

class A
{
public:
	A()
	{
		cout<<"A()"<<endl;
	}

	virtual ~A()
	{
		cout<<"~A()"<<endl;
	}
};

class B
{
public:
	B()
	{
		cout<<"B()"<<endl;
	}

	virtual ~B()
	{
		cout<<"~B()"<<endl;
	}
};

class C : public A, public B
{
public:
	C()
	{
		cout<<"C()"<<endl;
	}

	~C()
	{
		cout<<"~C()"<<endl;
	}
};

class AA
{
public:
	AA()
	{
		cout<<"AA()"<<endl;
	}

	virtual ~AA()
	{
		cout<<"~AA()"<<endl;
	}

};

class BB : public AA
{
public:
	BB()
	{
		cout<<"BB()"<<endl;
	}

	~BB()
	{
		// 
		cout<<"~BB()"<<endl;
	}


	//int * ptr;

};

int main()
{
	//C* pc = new C;
	//A* pa = pc;
	//B* pb = pc;

	//delete pb;

	Test();

	return 0;
}