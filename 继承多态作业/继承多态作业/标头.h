#pragma once
#include<iostream>
using namespace std;


typedef void(*FUNC)();
//
// 1.ʵ�����¼�����ĳ�Ա����
// 2.ʵ��һ���麯���ĸ��Ǽ�����
// 3.�������μ̳����⡣
//

// ֲ��
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
	string _name;		//����
};

class Tree :virtual public Botany
{
public:
	//...ʵ��Ĭ�ϵĳ�Ա����
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
	int _hight;		// �߶�
};

class Flower :virtual public Botany
{
public:
	//...ʵ��Ĭ�ϵĳ�Ա����
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
	int _colour;	// ��ɫ
};

// �����������������ǻ���
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