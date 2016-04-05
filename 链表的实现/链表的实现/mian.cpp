#include<stdio.h>
#include"head.h"


void testjoseph()
{
	ListNode *list;
	InitListNode(list);
	
	PushBack(list,2);
	PushBack(list,3);
	PushFront(list,1);
	PrintList(list);

	Loop(list);
	Joseph(list,Find(list,3),1);
	PrintList(list);
}



void test1()
{
	ListNode *list;
	InitListNode(list);
	
	PushBack(list,2);
	PushBack(list,1);
	PushFront(list,7);
	PrintList(list);
	InsertNonHead(Find(list,1),6);
	PrintList(list);
}




void testBubble()
{
	ListNode *list;
	InitListNode(list);
	
	PushBack(list,2);
	PushBack(list,1);
	PushFront(list,7);
	InsertNonHead(Find(list,1),6);
	PrintList(list);
	Bubble_Sort(list);
	PrintList(list);
}


void testloop()//有环的测试
{
	ListNode *list;
	InitListNode(list);
	
	PushBack(list,2);
	PushBack(list,3);
	PushFront(list,1);
	PrintList(list);

	Find(list,3)->next=Find(list,2);
	printf("入口节点的数为%d\n",HaveLoop(list)->_data);
	printf("%d\n",CountLoop(HaveLoop(list)));
}


void testcircle()
{
	ListNode *list;
	InitListNode(list);
	
	PushBack(list,2);
	PushBack(list,3);
	PushFront(list,1);
	PrintList(list);

	Find(list,3)->next=Find(list,2);
	if(HaveCircle(list))
	{
		printf("有环！");
	}//找到的是相遇的节点并不是换的入口处
	ListNode *ret=HaveCircle(list);
	printf("环的长度是%d",GetLength(ret));

}



void testbanana()
{
	ListNode *list1,*list2;
	InitListNode(list1);
	PushBack(list1,2);
	PushBack(list1,3);
	PushFront(list1,1);
	PrintList(list1);
	InitListNode(list2);
	PushBack(list2,5);
	PushBack(list2,6);
	PushFront(list2,4);
	PrintList(list2);
	ListNode *ret=Find(list2,6);
	ret->next=Find(list1,2);
	if(Isbanana_non(list1,list2))
	{
		printf("相交！");
	}
}

void main()
{
//	testjoseph();//约瑟夫环测试
//	testBubble();//冒泡测试
//	testbanana();//相交测试
//	testloop();//循环测试
	testcircle();
}