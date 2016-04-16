#include<iostream>

using namespace std;


class test
{
public:
	virtual void fun() 
	{}
public:
	static int a;
	int b;
};


int main()
{

	cout << sizeof(test);
	return 0;
	}