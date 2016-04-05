#include"БъЭЗ.h"



void test1()
{
	int a[5][5] =
	{
		{0,1,2,3,4},
		{1,0,1,2,3},
		{2,1,0,1,2},
		{3,2,1,0,1},
		{4,3,2,1,0},
	};
	SymmetryMatrix<int> sm((int *)a, 5);
	sm.Display();
}



void test2()
{
	int a[5][5]=
	{
		{0,1,0,2,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,3,0,4,0,},
		{0,0,0,0,0,},
	};
	SparseMatrix<int> sm((int *)a,5,5,0);
	sm.Display();
	SparseMatrix<int> sm_r = sm.Transpose();
	sm_r.Display();
}
int main()
{
	//test1();
	test2();
	return 0;
}