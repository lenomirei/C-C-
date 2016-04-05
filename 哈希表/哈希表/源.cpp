//#include"K.h"
//#include"KV.h"
#include"¹þÏ£Í°.h"

//void test()
//{
//	HashTable<int> h1(10);
//	h1.Insert(18);
//	h1.Insert(89);
//	h1.Insert(49);
//	h1.Insert(58);
//	h1.Insert(9);
//	h1.Insert(1);
//	h1.Insert(3);
//	h1.Insert(65);
//	h1.Insert(84);
//
//	cout << h1.Remove(58) << endl;
//	cout << h1.Find(9) << endl;
//
//}

//
//
//void teststring()
//{
//	HashTable<string> h1(10);
//	h1.Insert("Å¶ºðºð");
//	h1.Insert("Å¶ºÇºÇ");
//}






//void test2()
//{
//	HashTable<string, string> ht1(10);
//	ht1.Insert("Cross", "Ïà½»");
//	ht1.Insert("Banana", "Ïã½¶");
//	ht1.Insert("Apple", "Æ»¹û");
//	ht1.Insert("haha", "¹þ¹þ");
//	ht1.Insert("love", "°®");
//	ht1.Insert("road", "Â·");
//}


void test3()
{
	HashTable<int, int> ht1;
	for (int i = 0; i < 53; i++)
	{
		ht1.Insert(i, i);
	}
	ht1.Print();
	ht1.Insert(53, 53);
	ht1.Print();
}

void test4()
{
	HashTable<int, int> ht1;
	for (int i = 0; i < 53; i++)
	{
		ht1.Insert(i, i);
	}
	HashTable<int, int> ht2(ht1);
}



int main()
{
	test3();
//	test4();
	//test2();
	//test();
	//teststring();
	return 0;
}




