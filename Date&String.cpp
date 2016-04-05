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
//			//if () // ����
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
//	int _year ;     // ��
//	int _month ;    // ��
//	int _day ;      // ��
//};
//
//istream& operator>>(istream& is, Date& d)
//{
//	cout<<"������һ�����ڵ�������:";
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
//// �˵�
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
//	// new -> ����+���ù��캯����ʼ��
//
//	// malloc/operator new -> �����ڴ�
//	// new ��λ���ʽ ->��ʾ���ù��캯����ʼ��
//
//	//Test1* array1 = new Test1[10];
//
//	//delete[] array1;
//
//	// ģ��new[]
//	Test1* array2 = (Test1*)operator new(sizeof(Test1)*10 + 4);
//	*((int*)array2) = 10;
//	array2 = (Test1*)((int)array2 + 4);
//	for (int i = 0; i < 10; ++i)
//	{
//		new(array2 + i) Test1(20);
//	}
//
//	// ģ��delete[]
//	// �ȵ��������������ͷſռ�
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
//	//// û�е���������
//	//// ����
//
//	return 0;
//}


#include <iostream>
#include <assert.h>
using namespace std;

// ǳ������ֵ������ -> ���

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
//			char* tmp = new char[strlen(s._str) + 1];
//			strcpy(tmp, s._str);
//			delete[] _str;
//			_str = tmp;
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

namespace DP
{
	class String
	{
	public:
		String(const char* str = "")
		{
			int len = strlen(str);
			_capacity = len + 1;
			_size = len;
			_str = new char[_capacity];
			strcpy(_str, str);
		}

		void _Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		// ? �����
		String(const String& s)
			:_str(NULL)
		{
			String tmp(s._str);
			this->_Swap(tmp);
		}

		// ?
		//String& operator=(const String& s)
		//{
		//	if (this != &s)
		//	{
		//		String tmp(s._str);
		//		//swap(_str, tmp._str);
		//		this->_Swap(tmp);
		//      
		//	}
		//	return *this;
		//}

		String& operator=(String s)
		{
			//swap(_str, s._str);
			_Swap(s);
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
		void PushBack(char ch)
		{
			// ?
			/*_CheckCapacity(_size + 2);

			_str[_size++] = ch;
			_str[_size] = '\0';*/

			Insert(_size, ch);
		}

		void Insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			_CheckCapacity(_size + 2);

			int end = _size+1;
			//while (end >= (int)pos) //?
			while (end > pos) //?
			{
				_str[end] = _str[end-1];
				--end;
			}

			_str[pos] = ch;
			++_size;
		}

		void Insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			size_t strSize = strlen(str);
			_CheckCapacity(_size + 1 + strSize);

			// Ų������
			int end = _size;
			while (end >= (int)pos) //?
			{
				_str[end + strSize] = _str[end];
				--end;
			}

			//
			// strcpy;?
			while (*str)
			{
				_str[pos++] = *str++;
			}
			
			_size += strSize;
		}

		char& operator[](size_t index)
		{
			//assert(index < _size);
			return _str[index];
		}

		int Find(char ch)
		{
		/*	char* str = _str;
			while (*str)
			{
				if (*str == ch)
				{
					return (str - _str - 1);
				}

				++str;
			}

			return -1;*/

			char* str = _str;
			int begin = 0;
			while (str[begin])
			{
				if (str[begin] == ch)
				{
					return  begin;
				}

				++begin;
			}

			return -1;
		}

		/*void PushBack(char ch);
		void Insert(size_t pos, char ch);
		void Insert(size_t pos, const char* str);
		char& operator[](size_t index);*/
		//int Find(char ch);
		int Find(const char* str) // // "hello world"  "wor" ->6
		{
			const char* src = _str;
			const char* sub = str;

			int srcLen = _size;
			int subLen = strlen(sub);

			int srcIndex = 0;
			while (srcIndex <= srcLen - subLen)
			{
				// �Ƚ��Ӵ�
				int i = srcIndex;
				int j = 0;
				while (i < srcLen && j < subLen && src[i] == sub[j])
				{
					++i;
					++j;
				}

				if(j == subLen)
				{
					return srcIndex;
				}

				++srcIndex;
			}

			return -1;
		}

		bool Erase(size_t pos);
		bool Erase(size_t pos, size_t n);

	public:
		// ���ܵ���C��
		bool operator>(const String& s)
		{
			const char* str1 = _str;
			const char* str2 = s._str;

			while (*str1 && *str2)
			{
				if (*str1 > *str2)
				{
					return true;
				}
				else if (*str1 < *str2)
				{
					return false;
				}
				else
				{
					++str1;
					++str2;
				}
			}

			if (*str1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator<(const String& s)
		{
			return !((*this > s) || (*this == s));
		}

		bool operator>=(const String& s)
		{
			return *this > s || *this == s;
		}

		bool operator<=(const String& s)
		{
			return *this < s || *this == s;
		}

		bool operator==(const String& s)
		{
			const char* str1 = _str;
			const char* str2 = s._str;

			while (*str1 && *str2)
			{
				if (*str1 == *str2)
				{
					++str1;
					++str2;
				}
				else
				{
					return false;
				}
			}

			if (*str1 || *str2)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

	private:
		void _CheckCapacity(size_t size)
		{
			if (size > _capacity)
			{
				int newCapacity = size > 2*_capacity\
					? size : 2*_capacity;

				_str = (char*)realloc(_str, newCapacity);
				_capacity = newCapacity;
			}
		}

	private:
		char* _str;

		size_t _size;
		size_t _capacity;
	};

	void Test1()
	{
		String s1("hello world");
		String s2(s1);
		String s3("change world");
		s1 = s3;
		s1 = s1;

		String s4; // ""
		String s5(s4);
		s1 = s4;
	}

	void Test2()
	{
		String s1("change worlda");
		String s2("change world");
		cout<<(s1 > s2)<<endl;
		s1[0] = 'x';


		String s3("hello ld");
		s3.Insert(6, "wor");
		s3.Insert(0, 'c');

		String s4("abcdabcdefgh");
		cout<<"Ret Pos: "<<s4.Find("abcde")<<endl;
		cout<<"Ret Pos: "<<s4.Find("abcdei")<<endl;
	}	
}

#include<windows.h>

namespace COW
{
	//class String
	//{
	//public:
	//	String(const char* str)
	//		:_str(new char[strlen(str) + 1])
	//		,_pCount(new int(1))
	//	{
	//		strcpy(_str, str);
	//	}

	//	String(String& s)
	//		:_str(s._str)
	//		,_pCount(s._pCount)
	//	{
	//		++(*_pCount);
	//	}

	//	String& operator=(const String& s)
	//	{
	//		if (_str != s._str)
	//		{
	//			// �ͷ�ԭ����
	//			if (--(*_pCount) == 0)
	//			{
	//				delete _pCount;
	//				delete[] _str;
	//			}

	//			// ǳ�������������ü���
	//			_str = s._str;
	//			_pCount = s._pCount;
	//			++(*_pCount);
	//		}

	//		return *this;
	//	}

	//	~String()
	//	{
	//		if (--(*_pCount) == 0)
	//		{
	//			cout<<"delete[] _str"<<endl;
	//			delete _pCount;
	//			delete[] _str;
	//		}
	//	}

	//private:
	//	char* _str;
	//	//static int _count;

	//	int* _pCount;
	//};

	class String
	{
	public:
		String(const char* str)
			:_str(new char[strlen(str)+5])
		{
			_str += 4;
			strcpy(_str, str);

			_GetRefCount(_str) = 1;
		}

		String(const String& s)
			:_str(s._str)
		{
			++_GetRefCount(_str);
		}

		String& operator=(const String& s)
		{
			if (_str != s._str)
			{
				_Release();

				_str = s._str;
				++_GetRefCount(_str);
			}

			return *this;
		}

		~String()
		{
			_Release();
		}

		// Insert
		// Find

		char& operator[](size_t pos)//String* this
		{
			// �����ü�������1����Ҫ���дʱ����
			if (_GetRefCount(_str) > 1)
			{
				char* tmp = new char[strlen(_str) + 5];
				tmp += 4;
				strcpy(tmp, _str);
				_GetRefCount(tmp) = 1;

				--_GetRefCount(_str);
				_str = tmp;
			}

			return _str[pos];
		}

		//const String* this
		const char& operator[](size_t pos) const
		{
			return _str[pos];
		}

		int Find(const String& s)
		{
			cout<<"Find(const String& s)"<<endl;
			return -1;
		}

	private:
		int& _GetRefCount(char* _ptr)
		{
			return *((int*)(_ptr-4));
		}

		void _Release()
		{
			if (--_GetRefCount(_str) == 0)
			{
				delete[] (_str-4);
			}
		}

	private:
		char* _str;
	};

	//int String::_count = 0;

	// Copy On Write

	void Test1()
	{
		String s1("1111111111111111111111");
		String s2(s1);

		//// ��ʱҲ����
		//cout<<s1[0]<<endl;

		//// дʱ����
		//s1[0] = 'x';

		s1.Find("xxxx");
		s1.Find(s2);
	}
}

void Test5()
{
	int begin = GetTickCount();

	COW::String s1("1111111111111111111111111111111111111111");
	for (int i = 0; i < 1000000; ++i)
	{
		COW::String s2(s1);
		// cout<<s2<<endl;
		//...
	}

	int end = GetTickCount();

	cout<<end - begin<<endl;
}

#include <string>

int main()
{

	COW::Test1();
	//Test5();

	//string s1("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	//string s2(s1);

	//printf("%x, %x", s1.c_str(), s2.c_str());

	return 0;
}

