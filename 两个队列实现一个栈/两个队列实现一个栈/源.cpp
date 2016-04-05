#include"БъЭЗ.h"





void test()
{
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	while (s1.Size())
	{
		cout << s1.Top() << endl;
		s1.Pop();
	}
}

int main()
{
	test();
	return 0;
}