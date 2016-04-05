#pragma once
#include<iostream>
using namespace std;

class string
{
public :

	string(const char *str)
		:_str(new char[strlen(str)+1])
		,_pcount(new int(1))
	{
		strcpy(_str, str);
	}
	~string()
	{
		if (--(*_pcount) == 0)//在这句话里已经减过了
		{
			delete _pcount;
			delete[] _str;
		}
	}
	string & operator=(const string& s)
	{
		if (this != &s)
		{
			if (--(*_pcount) == 0)
			{
				delete _pcount;
				delete[] _str;
			}
			_str = s._str;
			_pcount = s._pcount;
			++(*_pcount);
		}
		return *this;
	}
private:
	char *_str;
	int *_pcount;
};


//class String
//{
//	friend ostream& operator<<(ostream& os, String &s);
//	
//public:
//	String(const char* str)
//		:_str(new char[strlen(str)+5])
//	{
//		*(int*)str = 1;
//		_str = _str + 4;
//	}
//	String(const String& s)
//		:_str(s._str)
//	{
//		++GetRefCount(_str);
//	}
//	~String()
//	{
//		if ((--GetRefCount(_str)) == 0)
//		{
//			delete[](_str - 4);
//		}
//	}
//	char& operator[](size_t index)
//	{
//		if (GetRefCount(_str) > 1)
//		{
//			--GetRefCount(_str);
//			char *tmp = new char[strlen(_str) + 5];
//			tmp += 4;
//			strcpy(tmp, _str);
//			GetRefCount(tmp)++;
//		}
//		return _str[index];
//	}
//	String& operator=(String &s)
//	{
//		if (_str != s._str)
//		{
//			if ((--GetRefCount(_str)) == 0)
//			{
//				delete[](_str - 4);
//			}
//			_str = s._str;
//			GetRefCount(_str)++;
//		}
//		return *this;
//	}
//private:
//	int& GetRefCount(char * _str)
//	{
//		return (*(int *)(_str - 4));
//	}
//private:
//	char *_str;
//};
//
//
//
//
//ostream& operator<<(ostream& os, String &s)
//{
//	os << s._str << endl;
//}