#include"БъЭЗ.h"



void test()
{
	Queue<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	q1.Push(5);
	q1.Pop();
	q1.Push(6);
	while(q1.Size())
	{
		cout << q1.Top() << endl;
		q1.Pop();
	}
}
int main()
{
	test();
	return 0;
}