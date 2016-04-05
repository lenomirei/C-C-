#include<stdio.h>
#include"header.h"



void main()
{
	SeqList t1;
	IniSeqList(&t1);
	PushBack(&t1,2);

	PushBack(&t1,3);
	PushBack(&t1,4);
	PushBack(&t1,5);
	PushBack(&t1,6);
	PushFront(&t1,1);
	PrintList(&t1);

	printf("%d",BinarySearch(&t1,6));
//	RemoveAll(&t1,5);
	PrintList(&t1);

}