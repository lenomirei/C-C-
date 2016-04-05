#include"БъЭЗ.h"


void test()
{
	Stack<int, 3> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);

	Stack<char, 3> s2;
	s2.Push('c');
	s2.Push('c');
	s2.Push('c');
	s2.Push('c');
	s2.Push('c');
	//s1.Push(6);
	//s1.Push(7);
	//s1.Push(8);
	//s1.Push(9);
	//s1.Push(10);
	//s1.Pop();
	//cout << s1.Top() << endl;
	//cout << s1.Empty() << endl;
	//s1.Push(11);
	//cout << s1.Top() << endl;
	//s1.Push(12);
	//cout << s1.Top() << endl;
	//cout << s1.Size() << endl;
}


int main()
{
	test();
	return 0;
}