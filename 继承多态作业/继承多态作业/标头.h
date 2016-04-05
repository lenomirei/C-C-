#pragma once
#include<iostream>
using namespace std;


typedef void(*FUNC)();
//
// 1.实现以下几个类的成员函数
// 2.实现一个虚函数的覆盖及调用
// 3.处理菱形继承问题。
//

// 植物
class Botany
{
public:
	Botany(string & name)
		:_name(name)
	{
		
	}
	virtual ~Botany()
	{
		cout << "Botany::~Botany()" << endl;
	}
	virtual void Display()
	{

	}
	virtual void func1()
	{
		cout << "Botany::func1()" << endl;
	}
protected:
	string _name;		//名字
};

class Tree :virtual public Botany
{
public:
	//...实现默认的成员函数
	Tree(string &name, int hight)
		:Botany(name)
		, _hight(hight)
	{
	}
	virtual ~Tree()
	{
		cout << "Tree::~Tree()" << endl;
	}
	virtual void Display()
	{

	}
	virtual void func1()
	{
		cout << "Tree::func1()" << endl;
	}
protected:
	int _hight;		// 高度
};

class Flower :virtual public Botany
{
public:
	//...实现默认的成员函数
	Flower(string &name, int colour)
		:Botany(name)
		, _colour(colour)
	{

	}
	virtual ~Flower()
	{
		cout << "Flower::~Flower()" << endl;
	}
	virtual void Display()
	{

	}
	virtual void func1()
	{
		cout << "Flower::func1()" << endl;
	}
protected:
	int _colour;	// 颜色
};

// 白兰花，既是树又是花。
class MicheliaAlba :public Flower,public Tree
{
public:
	// ...
	MicheliaAlba(string &name, int hight, int colour)
		:Botany(name)
		, Tree(name,hight)
		, Flower(name,colour)
	{

	}
	virtual ~MicheliaAlba()
	{
		cout << "MicheliaAlba::~MicheliaAlba()" << endl;
	}
	virtual void Display()
	{

	}
	virtual void func1()
	{
		cout << "MicheliaAlba::func1()" << endl;
	}
	virtual void func2()
	{
		cout << "func2()" << endl;
	}
	virtual void func3()
	{
		cout << "func3()" << endl;
	}
protected:
};
void PrintVtable(int *vTable)
{
	for (int i = 0; vTable[i] != 0; i++)
	{
		printf("%x\n", vTable[i]);
		FUNC f = (FUNC)vTable[i];
		f();
	}
}