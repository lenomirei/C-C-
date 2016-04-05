#include"БъЭЗ.h"

void main()
{
	int a[3] = { 1,2,3 };
	SeqList s1(a, 3);
	SeqList s2;
	s1 = s2;
	s1.Reserve(10);
}