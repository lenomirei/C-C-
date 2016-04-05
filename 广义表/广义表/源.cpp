#include"БъЭЗ.h"


void test()
{
	GeneralList l1("(1,2,(3,4),5)");
	l1.PrintList();
	cout << endl;
	cout << l1.Depth() << endl;
	GeneralList l2(l1);
	l2.PrintList();
	GeneralList l3("(1,2)");
	GeneralList l4("(1,2,(3,(4),5))");
	l3 = l4;
	l3.PrintList();
	l4.PrintList();
}


int main()
{
	test();
	return 0;
}
