#include <iostream>
#include"БъЭЗ.h"


void test()
{
	SeqList<int> s1;
	SeqList<int> s2;
	s2.PuchBack(3);
	s2.PuchBack(2);
	s2.PrintList();
	SeqList<int> s3(s2);
	s3.PrintList();
}



int main()
{
	test();
	return 0;
}
