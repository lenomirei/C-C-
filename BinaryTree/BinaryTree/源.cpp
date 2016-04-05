#include"标头.h"




void test()
{
	int a[10] = { 1,2,3,'#','#',4,'#','#',5,6 };
	BinaryTree<int> b1(a,10);
	//b1.PrevOrder();
	//b1.InOrder();
	//b1.LaOrder();
	b1.LevelOrder();
	cout << b1.Depth() << endl;
	cout << "size:" << b1.Size() << endl;
	BinaryTree<int> b2(b1);
	b2.InOrder();
	if (b1.Find(4))
	{
		cout << b1.Find(4)->_data << endl;
	}
	else
	{
		cout << "根本没有" << endl;
	}
	BinaryTree<int> b3(b1);
	//b3 = b2;
}



void test2()
{
	int a[10] = { 1,2,3,'#','#',4,'#','#',5,6 };
	BinaryTree<int> b1(a, 10);
	cout << "中序遍历" << endl;
	b1.InOrder_NonR();
	b1.InOrder();
	cout << "前序遍历" << endl;
	b1.PreOrder_NonR();
	b1.PrevOrder();

	cout << "后序遍历" << endl;
	b1.PostOrder_NonR();
	b1.LaOrder();
	
}





int main()
{
	test();
	//test2();
	return 0;
}