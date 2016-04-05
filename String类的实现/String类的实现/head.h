#include<iostream>
#include<assert.h>
using namespace std;


class String
{
public:
	String(const char*str="")
	{
		int len=strlen(str);
		_capacity=len+1;	
		_size=len;
		_str=new char[_capacity];
		strcpy(_str,str);
		cout << "���ù��캯��" << endl;
	}
	String(String &s)
	{
		cout << "�����˿������캯��" << endl;
	}
	String &operator=(const String& s)
	{
		cout << "�����˸�ֵ���������" << endl;
	}
	void Swap(String &s)
	{
		swap(_str,s._str);
		swap(_size,s._size);
		swap(_capacity,s._capacity);
	}


	void CheckCapacity(size_t size)
	{
		if(size>_capacity)
		{
			int newcapacity= size>2*_size?size :2*_size;
			_str=(char *)realloc(_str,newcapacity);
			_capacity=newcapacity;
			_size=size;
		}
	}//�ж��Ƿ�ȵ�ǰ�ַ������ȶ�����Ҫ������Ϊ�������һ���ַ�������ô�ܿ��ܲ���ĺܳ���ֻ�ӳ��������ܲ���ʲô�ã�

	void PushBack(char ch)
	{
		CheckCapacity(_size+2);
		_str[_size++]=ch;
		_str[_size]='\0';
	}

	void Insert(size_t pos,char ch)
	{
		assert(pos<_size);
		CheckCapacity(_size+1+1);
		size_t end=_size-1;
		while(end>=pos)
		{
			_str[end+1]=_str[end];
			end--;
		}
		_str[pos]=ch;
		_size++;
	}

	void Insert(size_t pos,const char *str)
	{
		
		assert(pos<_size);
		int len=strlen(str);
		CheckCapacity(_size+len+1);
		size_t end=_size-1;
		while(end>=pos)
		{
			_str[end+len]=_str[end];
			end--;
		}
		_size+=len;
		_str[_size]='\0';
	}



	char &operator [](size_t index)
	{
		assert(index<_size);
		return _str[index];
	}

	int Find(char ch)
	{
		for(int i=0;(_str+i)<(_str+_size);i++)
		{
			if(*(_str+i) == ch)
			{
				return i;
			}
		}
		return -1;
	}

	//int Find(const char*str)
	//{
	//	assert(str);
	//	assert(strlen(str)<_size);
	//	int flag;
	//	for(int i=0;i<_size;i++)
	//	{
	//		flag=1;
	//		for(int j=0;j<strlen(str);j++)
	//		{
	//			if(_str[i+j] != str[j])
	//			{
	//				flag=0;
	//				break;//�ַ�������ȣ�ֱ�Ӻ���
	//			}
	//		}
	//		if(flag == 1)
	//		{
	//			return i;
	//		}
	//	}
	//}//����ƥ��
	
	int Find(const char *str)
	{
		assert(str);
		assert(strlen(str)<_size);
		int flag;
		for(int i=0;i<_size;i++)
		{
			flag=1;
			for(int j=0;j<strlen(str);j++)
			{
				if(_str[i+j] != str[j])
				{
					flag=0;
					i=i+j;
					break;//�ַ�������ȣ�ֱ�Ӻ���
				}
			}
			if(flag == 1)
			{
				return i;
			}
		}
	}//KMP


	void Erase(size_t pos)
	{
		assert(pos>_size);
		size_t index=pos;
		while(index<_size)
		{
			_str[index]=_str[index+1];
			index++;
		}
		_size--;
	}//Ϊʲô��bool������ֵ���������ҵ��ض���ֵ����erase��ֻҪ��posֵ�Ϸ����Ϳ�����ô��



	void Erase(size_t pos,size_t n)
	{
		assert(pos>_size);
		size_t index=pos;
		while(index>_size-n)
		{
			_str[index]=_str[index+n];
			index++;
		}
		_size-=n;
	}


private:
	char *_str;
	size_t _size;
	size_t _capacity;

};