#include"БъЭЗ.h"



void test()
{
	Stack<int, 100> s1;
	s1.Push(3);
	s1.Push(2);
	s1.Push(5);
	s1.Push(1);
	cout << s1.Min() << endl;
	s1.Pop();
	cout << s1.Min() << endl;
}


int main()
{
	test();
	return 0;
}