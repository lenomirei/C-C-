#pragma once
#include<iostream>
#include"��ͷ.h"
using namespace std;


struct Node
{
	Type t;
	int value;
	Node(int x)
		:t(typeint)
		,value(x)
	{}
};

enum Type
{
	//һ����˵�ǲ���������һ��˵�ǲ�����
	typeint,
	typesym
};

enum TypeSymbol
{
	ADD,
	SUB,
	MUL,
	DIV
};


void Operator(struct Node x)
{
	Stack<Node, 10> s1;
	if (x.t==typeint)
	{
		s1.Push(x);
	}
	else
	{
		int left = s1.Top().value;
		s1.Pop();
		int right = s1.Top().value;
		s1.Pop();
		switch (s1.Top().value)
		{
		case ADD:
			s1.Push(left+right);
			break;
		case SUB:
			s1.Push(left - right);
			break;
		case MUL:
			s1.Push(left*right);
			break;
		case DIV:
			s1.Push(left/right);
			break;
		default:
			break;
		}
	}
}

int main()
{
	//���������Ѿ����˺�׺���ʽ
	return 0;
}