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


void testloop()//�л��Ĳ���
{
	ListNode *list;
	InitListNode(list);
	
	PushBack(list,2);
	PushBack(list,3);
	PushFront(list,1);
	PrintList(list);

	Find(list,3)->next=Find(list,2);
	printf("��ڽڵ����Ϊ%d\n",HaveLoop(list)->_data);
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
		printf("�л���");
	}//�ҵ����������Ľڵ㲢���ǻ�����ڴ�
	ListNode *ret=HaveCircle(list);
	printf("���ĳ�����%d",GetLength(ret));

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
		printf("�ཻ��");
	}
}

void main()
{
//	testjoseph();//Լɪ�򻷲���
//	testBubble();//ð�ݲ���
//	testbanana();//�ཻ����
//	testloop();//ѭ������
	testcircle();
}