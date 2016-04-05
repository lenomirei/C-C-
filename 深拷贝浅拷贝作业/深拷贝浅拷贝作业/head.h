#include<iostream>
#include<assert.h>
using namespace std;


class String
{
public:
	String(const char *str="")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str,str);
	}
	String()
	{
		*_str='\0';
	}
	~String()
	{
		delete[] _str;
		_str=NULL;
	}

	String(String &s)
		:_str(NULL)
	{
		String tmp(s._str);
		swap(_str,tmp._str);
	}
	//String(String &s)
	//{
	//	_str=new char[strlen(s._str) + 1];
	//	strcpy(_str,s._str);
	//}


	String & operator =(String &s)
	{
		
		if(this != &s)
		{
			String tmp(s);
			swap(_str,tmp._str);
		}
		return *this;
	}

	//String & operator =(  String & s)
	//{
	//	assert(s._str);
	//	if(this != &s)
	//	{
	//		if(_str)
	//		{
	//			delete[] _str;
	//		}
	//		_str=new char[sizeof(s)+1];
	//		strcpy(_str,s._str);
	//	}
	//	return *this;
	//}
	bool operator ==(  String s);
	bool operator >(  String s);

	bool operator <(  String s);

	bool operator <=(  String s);

	bool operator >=(  String s);




	//bool operator ==(  String s)//使用strlen可以预先判断字符串的长度是否相等
	//{
	//	//需要考虑如果String中的成员变量如果是为空指针的话怎么办
	//	if(strlen(s._str)!=strlen(_str))
	//	{
	//		return false;
	//	}
	//	else
	//	{
	//		char* pstr=_str;
	//		char* ps=s._str;

	//		while(*(pstr++)!='\0' && *(ps++)!='\0')
	//		{
	//			if(*pstr != *ps)
	//			{
	//				return false;
	//			}
	//		}
	//		return true;
	//	}
	//}
private:
	void CheckCapacity(size_t size)
	{
		if (size > _capacity)
		{
			size_t newcapacity = size > 2 * _capacity ? size : 2 * _capacity;
			_size = size;
			_capacity = newcapacity;
			_str = (char *)realloc(_str, newcapacity);
		}

	}
private:
	char *_str;
	size_t _size;
	size_t _capacity;
};



bool String::operator==(String s)
{
	char* pstr=_str;
	char* ps=s._str;

	while(*pstr!='\0' && *ps!='\0')
	{
		if(*pstr++ != *ps++)
		{
			return false;
		}
	}
	if(*pstr!='\0'||*ps!='\0')
	{
		return false;
	}
	return true;
}

bool String::operator >(  String s)
{
	char *pstr=_str;
	char *ps=s._str;
	while(*pstr!='\0' && *ps!='\0')
	{
		if(*pstr++ < *ps++)
		{
			return false;
		}

	}
	if(*ps!='\0')
	{
		return false;
	}
	return true;

}

bool String::operator <( String s)
{
	return !(*this==s || *this>s);
}



bool String::operator <=(  String s)
{
	return (*this<s || *this==s);
}
bool String::operator >=(  String s)
{
	return (*this>s || *this==s);
}