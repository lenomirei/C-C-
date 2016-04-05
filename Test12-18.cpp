//#include <iostream>
//using namespace std;
//
//class Base
//{
//public:
//	void DisplayBase()
//	{
//		cout<<"Base::DisplayBase()"<<endl;
//	}
//
//protected:
////private:
//	int _b;
//};
//
//class Derive : private Base
//{
//public:
//	void DisplayDerive()
//	{
//		DisplayBase();
//
//		cout<<_d<<endl;
//		cout<<_b<<endl;
//		cout<<"Derive::DisplayBase()"<<endl;
//	}
//
//private:
//	int _d;
//};
//
//struct A
//{
//public:
//	void f1()
//	{
//	}
//};
//
//struct B : public A
//{};
//
//int main()
//{
//	B b;
//	b.f1();
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	string _name;
//};
//
//class Student : private Person
//{
//public:
//	int _id;
//};
//
////
//// is_a
//// has_a
////
//int main()
//{
//	Person p;
//	Student s;
//
//	p = s; // 切片
//
//	return 0;
//}
//
////int main()
////{
////	//Person p;
////	//Student s;
////
////	//p._name = "人";
////	//s._name = "学生";
////	//s._id = 0;
////
////	////p = s; // 切片
////	////s = p;
////
////	//Person* p1 = &p;
////	//Person* p2 = &s;
////
////	//Person& r1 = p;
////	//Person& r2 = s;
////
////	//Student* p3  = &s;
////	//Student* p4  = (Student*)&p;
////
////	//p4->_id = 10;
////
////	//Student& r3 = s;
////	//Student& r4 = (Student&)p;
////
////	//r4._id  = 10;
////
////	int a = 0;
////	int* p = &a;
////	int& r = a;
////
////
////	return 0;
////}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	Person(const char* name = "")
//		:_name(name)
//	{
//		cout<<"Person()"<<endl;
//	}
//
//	Person(const Person& p)
//		:_name(p._name) // dp cow
//	{
//		cout<<"Person(const Person& p)"<<endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout<<"Person& operator=(const Person& p)"<<endl;
//
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//
//		return *this;
//	}
//
//	~Person() // Person* this
//	{
//		cout<<"~Person()"<<endl;
//	}
//
//protected:
//	string _name;
//};
//
//// 合成版本
//class Student : public Person
//{
//public:
//	Student(const char* name, int id)
//		:Person(name)
//		,_id(id)
//	{
//		cout<<"Student()"<<endl;
//	}
//
//	Student(const Student& s)
//		:Person(s)
//		,_id(s._id)
//	{
//		cout<<"Student(const Student& s)"<<endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			//Person::operator=(s);
//			_id = s._id;
//			*((Person*)this) = s;
//		}
//
//		cout<<"Student& operator=(const Student& s)"<<endl;
//
//		return *this;
//	}
//
//	~Student()
//	{
//		//Person::~Person(); // Student* this
//
//		cout<<"~Student()"<<endl;
//	}
//
//protected:
//	int _id;
//};
//
//int main()
//{
//	Student s1("peter", 18);
//	Student s2(s1);
//
//	Student s3("jack", 19);
//	
//	s3 = s1;
//}


#include <iostream>
#include <string>
using namespace std;

class Person
{
	// 68
protected :
	string _name ;          // 姓名 // 32
	string _sex ;           // 性别 // 32
	int _age ;              // 年龄 // 4
};

class Student : virtual public Person
{
	friend void Display ( Person& p , Student& s);
protected :
	int _stuNum;      //学号
};

class Graduate : public Student
{
protected :
	string _seminarCourse ;     // 研究科目
};

class Teacher : virtual public Person
{
protected :
	int _employeeId ;          // 职工编号
};

class GraduateAffiliates : public Graduate, public Teacher
{};

void TestPerson1 ()
{
	GraduateAffiliates ga;
	cout<<sizeof(ga)<<endl;

	cout<<sizeof(string)<<endl;
}

class A
{
public:
	void f();

	int _a;
};

class B : protected A
{};

int main()
{
	//TestPerson1();

	A a;
	B b;

	a._a = 1;
	b._a = 2;

	a = b;

	return 0;
}