#include"БъЭЗ.h"


void test()
{
	SXList<int> l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	l1.Reverse();
	l1.PrintList();
}


int main()
{
	test();
	return 0;
}