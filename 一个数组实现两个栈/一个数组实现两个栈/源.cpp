#include"БъЭЗ.h"




void test()
{
	Stack<int> s;
	s.Push(1, 1);
	s.Push(2, 1);
	s.Push(3, 1);
	s.Push(4, 1);
	s.Push(5, 1);
	s.Push(1, 2);
	s.Push(2, 2);
	s.Push(3, 2);
	s.Push(4, 2);
	s.Push(5, 2);
	s.Pop(1);
	cout << s.Top(1) << endl;
}

int main()
{
	test();
	return 0;
}
