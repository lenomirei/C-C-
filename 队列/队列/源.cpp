#include"БъЭЗ.h"



void test()
{
	Queue<int> q1;
	cout << q1.Empty() << endl;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	cout << q1.Empty() << endl;
	q1.Push(5);
	q1.Push(6);
	q1.Push(7);
	q1.Push(8);
	cout << q1.Size() << endl;
	cout << q1.Front() << endl;
	cout << q1.Back() << endl;
	q1.Pop();
	cout << q1.Size() << endl;
	Queue<int > q2(q1);
}


int main()
{
	test();
	return 0;
}