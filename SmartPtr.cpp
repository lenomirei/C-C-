//#include <iostream>
//using namespace std;
//
//void Test1()
//{
//	int* p1 = new int[10]; // 智能指针
//	int* p2 = NULL;
//
//	try
//	{
//		p2 = new int[0x7fffffff/4];
//	}
//	catch(...)
//	{
//		delete[] p1;
//		throw;
//	}
//
//	//if (true)
//	//{
//	//	delete[] p1;
//	//	return;
//	//}
//	//try
//
//	//{
//	//	if (true)
//	//	{
//	//		throw 1;
//	//	}
//	//}
//	//catch(...)
//	//{
//	//	delete[] p1;
//	//	throw;
//	//}
//
//	//Some();
//
//	delete[] p2;
//	p2 = NULL;
//
//	delete[] p1;
//	p1 = NULL;
//}
//
//int main()
//{
//	try
//	{
//		Test1();
//	}
//	catch(exception& e)
//	{
//		cout<<e.what()<<endl;
//	}
//	//catch(BaseException& e)
//	//{}
//	catch(...)
//	{
//		cout<<"未知异常"<<endl;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//template<class T>
//class AutoPtr
//{
//public:
//	AutoPtr(T* ptr = NULL)
//		:_ptr(ptr)
//	{}
//
//	AutoPtr(AutoPtr<T>& ap)
//		:_ptr(ap._ptr)
//	{
//		ap._ptr = NULL;
//	}
//	
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		if (_ptr != ap._ptr)
//		{
//			delete _ptr;
//
//			_ptr = ap._ptr;
//			ap._ptr = NULL;
//		}
//
//		return *this;
//	}
//
//	~AutoPtr()
//	{
//		cout<<"释放内存->"<<_ptr<<endl;
//		delete _ptr;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	T* GetPtr()
//	{
//		return _ptr;
//	}
//
//private:
//	T* _ptr;
//};
//
//class AA
//{
//public:
//	void Display()
//	{
//		cout<<_a<<endl;
//	}
//
//private:
//	int _a;
//};
//
//void Test1()
//{
//	//int* p1 = new int; -> *p1 = 10
//	//int* p2 = new int;
//	AutoPtr<int> ap1 = new int; // 智能指针--像指针的一样的类型
//								// 管理的是释放
//	//AutoPtr<int> ap2 = new int;
//	//int* p2 = new int[0x7fffffff/4];
//
//	//delete p1;
//	//delete p2;
//}
//
//void Test2()
//{
//	// 智能指针
//	AutoPtr<int> ap1 = new int(1);
//	AutoPtr<int> ap2 = new int(2);
//	*ap1 = 10;
//	*ap2 = 10;
//
//	AutoPtr<AA> ap3 = new AA;
//	(*ap3).Display();
//	ap3->Display();
//}
//
////void f(int* p1)
//
//void Test3()
//{
//	//int* ptr1 = new int(10);
//	AutoPtr<int> ap1 = new int(1);
//	AutoPtr<int> ap2(ap1);
//	AutoPtr<int> ap3(ap2);
//
//	//*ap1 = 10;
//
//	AutoPtr<int> ap4;
//	ap4 = ap3;
//
//	AutoPtr<int> ap5 = new int(10);
//	ap5 = ap4;
//}
//
//int main()
//{
//	try
//	{
//		Test3();
//	}
//	catch (exception& e)
//	{
//		cout<<e.what()<<endl;
//	}
//	catch(...)
//	{}
//	
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//template<class T>
//class ScopedPtr
//{
//public:
//	ScopedPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	~ScopedPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//		}
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* GetPtr()
//	{
//		return _ptr;
//	}
//
//private:
//	ScopedPtr(const ScopedPtr<T>& sp);
//	ScopedPtr<T>& operator=(const ScopedPtr<T>& sp);
//
//private:
//	T* _ptr;
//};
//
//void Test1()
//{
//	ScopedPtr<int> sp1 = new int(1);
//	ScopedPtr<int> sp2 = new int(1);
//	ScopedPtr<int> sp3(sp1);
//
//	sp1 = sp2;
//}
//
//int main()
//{
//	try
//	{
//		Test1();
//	}
//	catch (exception& e)
//	{
//		cout<<e.what()<<endl;
//	}
//	catch(...)
//	{}
//	
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//template<class T>
//class SharedPtr
//{
//public:
//	SharedPtr(T* ptr)
//		:_ptr(ptr)
//		,_pCount(new int(1))
//	{}
//
//	SharedPtr(SharedPtr<T>& sp)
//		:_ptr(sp._ptr)
//		,_pCount(sp._pCount)
//	{
//		//++(*_pCount);
//		_AddRef();
//	}
//
//	SharedPtr<T>& operator=(SharedPtr<T>& sp)
//	{
//		/*if (--(*_pCount) == 0)
//		{
//			delete _ptr;
//			delete _pCount;
//		}*/
//
//		this->_Realse();
//
//		_ptr = sp._ptr;
//		_pCount = sp._pCount;
//
//		//++(*_pCount);
//		_AddRef();
//
//		return *this;
//	}
//
//	~SharedPtr()
//	{
//		if (--(*_pCount) == 0)
//		{
//			//delete _ptr;
//
//			deleter(_ptr);
//
//			delete _pCount;
//		}
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	T* GetPtr()
//	{
//		return _ptr;
//	}
//
//protected:
//	void _AddRef()
//	{
//		++(*_pCount);
//	}
//
//	void _Realse()
//	{
//		if (--(*_pCount) == 0)
//		{
//			delete _pCount;
//			delete _ptr;
//			_pCount = NULL;
//			_ptr = NULL;
//		}
//	}
//
//private:
//	T* _ptr;
//	int* _pCount;
//};
//
//void Test1()
//{
//	SharedPtr<int> sp1 = new int(10);
//	SharedPtr<int> sp2 = new int(11);
//	SharedPtr<int> sp3(sp1);
//
//	sp1 = sp2;
//	*sp3 = 20;
//}
//
//int main()
//{
//	try
//	{
//		Test1();
//	}
//	catch (exception& e)
//	{
//		cout<<e.what()<<endl;
//	}
//	catch(...)
//	{}
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//#include <memory>
//
//class AA
//{
//public:
//
//	~AA()
//	{}
//
//	bool operator>(const AA& aa) const
//	{
//		return _a > aa._a;
//	}
//
//private:
//	int _a;
//};
//
//// 仿函数
//template<class T>
//struct Greater
//{
//	bool operator() (const T& l, const T& r)
//	{
//		return l > r;
//	}
//};
//
//template<class T>
//struct Less
//{
//	bool operator() (const T& l, const T& r)
//	{
//		return l < r;
//	}
//};
//
//template<class T>
//void Sort(T* array, size_t size)
//{
//	// 冒泡
//	for (;;)
//	{
//		for (;;)
//		{
//			//1. > 升序
//			//2. < 降序
//			if (array[i] >array[i+1])
//			{
//				swap()
//			}
//		}
//	}
//}
//
//template<class T, class Compare = Greater<T> >
//void Sort(T* array, size_t size)
//{
//	Compare com;
//	// 冒泡
//	for (;;)
//	{
//		for (;;)
//		{
//			//1. > 升序
//			//2. < 降序
//			//if (array[i] > array[i + 1])
//			if (com(array[i], array[i+1])) // 仿函数
//			{
//				swap()
//			}
//		}
//	}
//}
//
//Sort(array, 10);
//Sort<int, Less<int>>(array, 10);
//
//int main()
//{
//	AA aa1, aa2;
//	cout << (aa1 > aa2) << endl;; // -> operator>
//	Greater<AA> greater;
//
//
//	cout << greater(aa1, aa2) << endl;;
//
//	//shared_ptr<AA> p1(new AA[10]);
//
//	return 0;
//}

#include <iostream>
using namespace std;

#include <memory>

class AA
{
public:

	~AA()
	{}

	bool operator>(const AA& aa) const
	{
		return _a > aa._a;
	}

private:
	int _a;
};

template<class T>
struct DeleteArray 
{
	void operator() (T* ptr)
	{
		delete[] ptr;
	}
};

template<class T>
struct Free
{
	void operator() (T* ptr)
	{
		free(ptr);
	}
};

template<class T>
struct Fclose
{
	void operator() (T* ptr)
	{
		fclose(ptr);
	}
};

int main()
{
	// 仿函数--定置删除器
	{
		shared_ptr<AA> p1(new AA[10], DeleteArray<AA>());
		shared_ptr<int> p2((int*)malloc(sizeof(int)* 10), Free<int>());

		Fclose<FILE> fclose;
		shared_ptr<FILE> p3(fopen("Test.txt", "w"));
	}

	return 0;
}


