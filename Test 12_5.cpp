//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//class Date
//{
//public :
//	Date (int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{
//		assert(year >= 1900);
//		assert(month > 0 && month < 13);
//
//		assert(day > 0 && day <= GetMonthDay(year, month));
//	}
//
//	Date operator+(int day)
//	{
//		Date tmp(*this);
//
//		if (day < 0)
//		{
//			return *this - (-day);
//		}
//
//		tmp._day += day;
//		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//		{
//			tmp._day -= GetMonthDay(tmp._year, tmp._month);
//
//			if (tmp._month == 12)
//			{
//				tmp._year++;
//				tmp._month = 1;
//			}
//			else
//			{
//				++tmp._month;
//			}
//		}
//
//		return tmp;
//	}
//
//	Date& operator+=(int day)
//	{
//		*this = *this + day;
//		return *this;
//	}
//
//	Date operator-(int day)
//	{
//		Date tmp(*this);
//		if (day < 0)
//		{
//			return *this + (-day);
//		}
//
//		tmp._day -= day;
//		while (tmp._day <= 0)
//		{
//			if (tmp._month == 1)
//			{
//				tmp._year--;
//				tmp._month = 12;
//			}
//			else
//			{
//				--tmp._month;
//			}
//
//			tmp._day += GetMonthDay(tmp._year, tmp._month);
//		}
//
//		return tmp;
//	}
//
//	Date& operator-=(int day)
//	{
//		*this = *this - day;
//		return *this;
//	}
//
//	Date& operator++()
//	{
//	/*	*this += 1;
//		return *this;*/
//
//		//*this = (*this)++;
//		(*this)++;
//		return *this;
//	}
//
//	Date operator++(int) 
//	{
//		Date tmp(*this);
//		*this += 1;
//		return tmp;
//
//		//Date tmp(*this);
//		//++(*this);
//		//return tmp;
//	}
//
//	Date& operator--();
//	Date operator--(int);
//
//	int operator-(const Date& d)
//	{
//		int flag = 1;
//		Date max = *this;
//		Date min = d;
//
//		if (*this < d)
//		{
//			min = *this;
//			max = d;
//			flag = -1;
//		}
//
//		int days = 0;
//		//while (min._year < max._year)
//		//{
//			//days += 365;
//			//if () // 润年
//			//{
//			//}
//		//}
//
//		while (min != max)
//		{
//			++min;
//			days++;
//		}
//
//		return flag*days;
//	}
//
//	bool operator>(const Date& d)
//	{
//		return (_year > d._year 
//			|| (_year == d._year && _month > d._month)
//			|| (_year == d._year && _month == d._month && _day > d._day));
//
//		/*if (_year > d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year)
//		{
//			if (_month > d._month)
//			{
//				return true;
//			}
//			else if(_month == d._month)
//			{
//				if (_day > d._day)
//				{
//					return true;
//				}
//			}
//		}
//
//		return false;*/
//	}
//
//	bool operator==(const Date& d)
//	{
//		return _year==d._year
//			&&_month==d._month
//			&&_day==d._day;
//	}
//
//	bool operator!=(Date& d)
//	{
//		return !(*this == d);
//	}
//	bool operator<(const Date& d)
//	{
//		return !(*this>d || *this==d);
//	}
//
//	bool operator<=(const Date& d)
//	{
//		return *this<d || *this==d;
//	}
//
//	void Display ();
//
//private:
//	int GetMonthDay(int year, int month)
//	{
//		assert(year >= 1900);
//		assert(month > 0 && month < 13);
//
//		static int monthArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//
//		int day = monthArray[month];
//
//		if ((month == 2) && (year%400 || (year%4 && year%100)))
//		{
//			day += 1;
//		}
//
//		return day;
//	}
//
//	friend istream& operator>>(istream& is, Date& d);
//	friend ostream& operator<<(ostream& os, const Date& d);
//
//private :
//	int _year ;     // 年
//	int _month ;    // 月
//	int _day ;      // 日
//};
//
//istream& operator>>(istream& is, Date& d)
//{
//	cout<<"请输入一个日期的年月日:";
//	is>>d._year>>d._month>>d._day;
//
//	return is;
//}
//
//ostream& operator<<(ostream& os, const Date& d)
//{
//	cout<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
//	return os;
//}
//
//void Date::Display ()
//{
//	cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
//}
//
//// 菜单
//// operator<< / operator>>
//
//void Test1()
//{
//	Date d1(2015, 11, 29);
//	d1.Display();
//
//	Date ret = d1 + 40; //operator+
//	ret.Display();
//
//	d1 = ret;
//	ret =  d1 - 40;
//	ret.Display();
//
//	Date d2(2015, 1, 1);
//	ret = d2 - 1;
//	ret.Display();
//}
//
//void Test2()
//{
//	Date d1(2015, 12, 3);
//	(d1++).Display();  //d1.operator++(&d1, 0);
//	(++d1).Display(); //d1.operator++(&d1);
//
//
//	Date d2(2015, 11, 1);
//	cout<<(d1 - d2)<<endl;
//}
//
//int main()
//{
//	int a = 1;
//	a = a++;
//	cout<<a<<endl;
//
//	Date d1(2015, 12, 5);
//	d1 = d1++;
//	cout<<d1<<endl;
//
//	return 0 ;
//}

//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//class Date
//{
//public :
//	/*Date (int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}*/
//
//	Date (int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Test1
//{
//public:
//	Test1(int t = 0)
//	{
//		cout<<"Test1(int t = 0)"<<endl;
//		_t1 = t;
//	}
//
//	~Test1()
//	{
//		cout<<"~Test1()"<<endl;
//	}
//
//private:
//	int _t1;
//};
//
//int main()
//{
//	//Test1* p1 = (Test1*)malloc(sizeof(Test1));
//	//new(p1) Test1(10);
//
//	// new -> 分配+调用构造函数初始化
//
//	// malloc/operator new -> 分配内存
//	// new 定位表达式 ->显示调用构造函数初始化
//
//	//Test1* array1 = new Test1[10];
//
//	//delete[] array1;
//
//	// 模拟new[]
//	Test1* array2 = (Test1*)operator new(sizeof(Test1)*10 + 4);
//	*((int*)array2) = 10;
//	array2 = (Test1*)((int)array2 + 4);
//	for (int i = 0; i < 10; ++i)
//	{
//		new(array2 + i) Test1(20);
//	}
//
//	// 模拟delete[]
//	// 先调析构函数，再释放空间
//	int count = *((int*)array2 - 1);
//	for (int i = 0; i < count; ++i)
//	{
//		array2[i].~Test1();
//	}
//	array2 = (Test1*)((int)array2 - 4);
//	operator delete(array2);
//
//	return 0;
//}


//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//class Date
//{
//public :
//	/*Date (int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}*/
//
//	Date (int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Test1
//{
//public:
//	Test1(int t = 0)
//	{
//		cout<<"Test1(int t = 0)"<<endl;
//		_t1 = t;
//
//		// malloc / open ...
//	}
//
//	//~Test1()
//	//{
//	//	cout<<"~test1()"<<endl;
//
//	//	// free / close ..
//	//}
//
//private:
//	int _t1;
//};
//
//int main()
//{
//	//int* p1 = new int;
//	//free(p1); // delete p1;
//
//	//int* p2 = new int[10];
//	//free(p2);
//
//	/*Test1* p3 = new Test1;
//	free(p3);*/
//
//	//Test1* p4 = new Test1[10];
//	////delete p4;
//	//free(p4);
//	//// 没有调析构函数
//	//// 崩溃
//
//	return 0;
//}


#include <iostream>
#include <assert.h>
using namespace std;

// 浅拷贝（值拷贝） -> 深拷贝

//class String
//{
//public:
//	String()
//		:_str(new char[1])
//	{
//		//_str = "";
//		//_str[0] = '\0';
//		*_str = '\0';
//		//*_str = 0;
//	}
//
//	String(char* str)
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}
//
//	String(const String& s)
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			delete[] _str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//
//		return *this;
//	}
//
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = NULL;
//		}
//	}
//
//private:
//	char* _str;
//};

class String
{
public:
	String(const char* str = "")
		:_str(new char [strlen(str) + 1])
	{
		strcpy(_str, str);
	}

	// ? 会崩溃
	String(const String& s)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}

	// ?
	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		String tmp(s._str);
	//		swap(_str, tmp._str);
	//	}
	//	return *this;
	//}

	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}

public:
	// 不能调用C库
	bool operator>(const String& s);
	bool operator<(const String& s);
	bool operator>=(const String& s);
	bool operator<=(const String& s);
	bool operator==(const String& s);

private:
	char* _str;
};

void Test1()
{
	String s1("hello world");
	//String s2(s1);
	String s3("change world");
	s1 = s3;

	String s4; // ""
	//String s5(s4);
	s1 = s4;
}

int main()
{
	Test1();

	return 0;
}