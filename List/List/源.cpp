#include"БъЭЗ.h"


void testinsert()
{
	List l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(4);
	l.PushBack(5);
	ListNode *tmp = l.Find(2);
	l.Insert(tmp, 3);
	l.display();
}


int main()
{
	testinsert();
	return 0;
}