#include<stdio.h>
#include"SeqList_D.h"

int main()
{
	SeqList t1;
	PushBack(&t1,1);
	PushBack(&t1,2);
	PushBack(&t1,3);
	PushBack(&t1,4);
	PushFront(&t1,0);
	return 0;
}
