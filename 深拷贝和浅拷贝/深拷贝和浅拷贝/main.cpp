#include<iostream>
#include<assert.h>
using namespace std;

class String 
{
public:
	String():_str(new char[1])
	{
		//_str="";//ָ���˴����,��Ϊ""����൱��һ���ַ�����char*     _strָ��ı䣬ָ���˴����
		_str[0]='\0';

		
	}
	String(char *str)
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str,str);
		cout << "�����˹��캯��" << endl;
	}
	String(const String& s)
	{
		_str=new char[strlen(s._str)+1];
		strcpy(_str,s._str);
		cout << "�����˿������캯��" << endl;
	}

	String & operator =(String & s)
	{
		assert(s._str);
		if(this!=&s)
		{
			if(_str)
			{
				delete[] _str;
			}
			_str=new char[sizeof(s)+1];
			strcpy(_str,s._str);
		}
		cout << "�����˸�ֵ�������������" << endl;
		return *this;
	}


	~String()
	{

	}
private:
	char* _str;
};



void test()
{
	String tmp = "test";
}


int main()
{
	/*String s1("hello world");
	String s2("change world");*/zz
	//String s3;

	test();
	/*s1=s2;*/
}