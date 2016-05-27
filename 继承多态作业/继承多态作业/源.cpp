#include"БъЭЗ.h"

int main()
{
	string s("a");
	Botany b(s);
	Tree t(s,10);
	Flower f(s,10);
	MicheliaAlba m(s, 10, 10);
	MicheliaAlba m1(s, 12, 13);
	int *vTable = (int *)(*(int *)&m);
	PrintVtable(vTable);
	return 0;


	
}