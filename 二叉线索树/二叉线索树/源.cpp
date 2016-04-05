#include"БъЭЗ.h"



int main()
{
	int a[10] = { 1,2,3,'#','#',4,'#','#',5,6 };
	int b[11] = { 1,2,3,'#','#',4,'#','#',5,6,7 };
	BinaryTree_Th<int> b1(a, 10);
	b1.InOrderThread();
	b1.InOrder();
	BinaryTree_Th<int> b2(b, 11);
	b2.PrevOrderThread();
	b2.PrevOrder();
	BinaryTree_Th<int> b3(b, 11);
	b3.PostOrderThread();
	b3.PostOrder();
	return 0;
}