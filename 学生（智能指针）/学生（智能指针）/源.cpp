//#include<iostream>
//using namespace std;
//
//
//void test()
//{
//
//	int *p1 = new int[10];
//	int *p2 = new int[0x7fffffff/4];//诺此时此处开辟失败抛出异常p1就会变成野指针
//	//if (true)
//	//{
//	//	delete[] p1;
//	//	return ;
//	//}//在此处发生内存泄露
////
////	if (true)
////	{
////		throw 1;
////	}
////
////	catch (...)
////	{
////		delete[] p1;
////		return;
////	}
////	delete[] p1;
//	delete[] p1;
//	delete[] p2;
//}
//
//int  main()
//{
//	try
//	{
//		test();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//	return 0;
//}
//
//
//
//
//#include<iostream>
//using namespace std;
//
//
//
//
//template<class T>
//
//
//class AutoPtr
//{
//public:
//	AutoPtr(T* ptr=NULL)
//		:_ptr(ptr)
//	{
//	}
//	AutoPtr(AutoPtr& ap)
//		:_ptr(ap._ptr)
//	{
//		ap._ptr = NULL;
//	}
//	~AutoPtr()
//	{
//		delete _ptr;
//	}
//	AutoPtr& operator=(AutoPtr& ap)
//	{
//		if (_ptr != ap._ptr)
//		{
//			if (NULL == _ptr)
//			{
//				_ptr = ap._ptr;
//				ap._ptr = NULL;
//			}
//			else
//			{
//				delete _ptr;
//				_ptr = ap._ptr;
//				ap._ptr = NULL;
//			}
//		}
//		return *this;
//	}
//	T& operator *()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//	T* GetPtr()
//	{
//		return _ptr;      
//	}
//private:
//	T* _ptr;
//};
//
//
//
//void test1()
//{
//	AutoPtr<int > ap1 = new int;//支持强转
//	AutoPtr<int > ap2 = new int;
//	//AutoPtr<int >ap3(ap1);//当心，深浅拷贝
//	AutoPtr<int > ap4;
//	ap4 = ap1;
//	ap2 = ap1;
//	/*int *p1 = new int;
//	int *p2 = new int;
//	delete p1;
//	delete p2;*/
//}
//int main()
//{
//
//	test1();
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//
//
//
//template<class T>
//class ScopedPtr
//{
//public:
//	ScopedPtr(T* ptr=NULL)
//		:_ptr(ptr)
//	{
//	}
//	~ScopedPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//		}
//	}
//	T* operator ->()
//	{
//		return _ptr;
//	}
//	T& operator *()
//	{
//		return *_ptr;
//	}
//	T* GetPtr()
//	{
//		return _ptr;
//	}
//
//private:
//	ScopedPtr(ScopedPtr& sp)
//	{
//
//	}
//	ScopedPtr& operator=()
//	{
//
//	}
//private:
//	T* _ptr;
//};
//
//
//
//void test1()
//{
//
//	ScopedPtr<int> sp1 = new int(1);
//	ScopedPtr<int> sp2 = new int(2);
//	ScopedPtr<int> sp3(sp1);
//}
//
//int main()
//{
//	test1();
//	return  0;
//}


#include<iostream>
using namespace std;
template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		,_pCount(new int(1))
	{

	}
	SharedPtr(SharedPtr& sp)
		:_ptr(sp._ptr)
		,_pCount(sp._pCount)
	{
		(*_pCount)++;
	}
	~SharedPtr()
	{
		if (--(*_pCount) == 0)
		{
			delete _ptr;
			delete _pCount;
		}
	}
	SharedPtr& operator=(SharedPtr& sp)
	{
		if (_ptr != sp._ptr)
		{
			if (NULL == _ptr)
			{
				_ptr = sp._ptr;
				_pCount = sp._pCount;
			}
			else
			{
				_Release();
			}
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
protected:
	void _AddRef()
	{
		++(*_pCount);
	}
	void _Release()
	{
		if (--(*_pCount) == 0)
		{
			delete _ptr;
			delete _pCount;
			_ptr = NULL;
			_pCount = NULL;
		}
	}
private:
	T* _ptr;
	int* _pCount;
};




int main()
{
	SharedPtr<int> s = new int(20);
	SharedPtr<int> s1(s);
	return 0;
}