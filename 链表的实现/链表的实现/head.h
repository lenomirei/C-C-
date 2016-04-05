#include<malloc.h>
#include<assert.h>




//insert 可以利用tmp来抵消顺序
typedef int DataType;
typedef struct ListNode
{
	DataType _data;
	struct ListNode *next;
}ListNode;

void InitListNode(ListNode *& pHead)
{
	pHead=NULL;
}



ListNode *Find(ListNode *pHead , DataType x)//pHead没有改变，可以不用引用？？
{
	ListNode *cur=pHead;
	while(cur)
	{
		if(x == cur->_data)
		{
			return cur;
		}
		cur=cur->next;
	}
	return NULL;
}






void PrintList(ListNode *pHead)
{
	ListNode *cur=pHead;
	while(cur)
	{
		printf("%d->",cur->_data);
		cur=cur->next;
	}
	printf("NULL");
	printf("\n");
}



ListNode *BuyNode(DataType x)
{
	ListNode *tmp;
	tmp=(ListNode *)malloc(sizeof(ListNode));
	tmp->next=NULL;
	tmp->_data=x;
	return tmp;
}


void Insert(ListNode *pos , DataType x)//这个函数有问题，当pos指向最后一个节点的时候会因为访问NULL而崩溃
{
	assert(pos);
	ListNode *tmp=pos->next;
	pos->next=BuyNode(x);
	pos->next->next=tmp;
}


void PushBack(ListNode * &pHead , DataType x)//1.链表为空2.链表不为空
{
	if(NULL == pHead)
	{
		pHead=BuyNode(x);
	}
	else
	{
		ListNode *tail=pHead;
		while(tail->next != NULL)
		{
			tail=tail->next;
		}
		tail->next=BuyNode(x);
	}

}



void PushFront(ListNode *&pHead , DataType x)//1.链表为空2.链表不为空
{
	if(NULL == pHead)
	{
		pHead=BuyNode(x);
	}
	else
	{
		ListNode *tmp;
		tmp=BuyNode(x);
		tmp->next=pHead;
		pHead=tmp;//更改了pHead需要用引用
	}
}

void PopBack(ListNode *pHead)//1.链表为空2.链表只有一个元素3.链表有许多元素
{
	if(NULL == pHead)
	{
		printf("The List is Empty");
		return ;
	}
	else if(NULL == pHead->next)
	{
		free(pHead);
		pHead = NULL;
	}
	else
	{
		ListNode *pretail=NULL,*tail=pHead;
		while(tail->next != NULL)
		{
			pretail=tail;
			tail=tail->next;
		}
		free(tail);
		pretail->next=NULL;
	}
}


void PopFront(ListNode *&pHead)//1.链表为空2.链表只有一个节点3.链表有许多节点
{
	if(NULL == pHead)
	{
		printf("The list is Empty");
		return ;
	}
	else if(NULL == pHead->next)
	{
		free(pHead);
		pHead=NULL;
	}
	else
	{
		ListNode *next=pHead->next;
		free(pHead);
		pHead=next;
	}
}//如果这里不采用引用无法传值




void Erase(ListNode *&pHead , ListNode *pos)//1.链表为空2.链表只有一个值3.链表中有许多值
{//应该分为两种情况，一种是找到的pos是头部，另一种情况是找到的pos不是链表的头部
	assert(pHead);
	if(pos == pHead)
	{
		pHead=pHead->next;
		free(pos);
	}
	else
	{
		ListNode *target=pos,*pretarget=pHead;
		while(pretarget)
		{
			if(pretarget->next == target)
			{
				pretarget->next=target->next;
				free(target);
				break;
			}
			pretarget=pretarget->next;
		}
		
	}

}




void Remove(ListNode *&pHead , DataType x)//1.第一个要删除的节点就是
{
	if(pHead->_data == x)
	{
		ListNode *next=pHead->next;
		free(pHead);
		pHead=next;
	}
	ListNode *preTarget=NULL,*target=pHead;
	while(target)
	{
		if(x == target->_data)
		{
			ListNode *next=target->next;
			free(target);
			preTarget->next=next;
			break;
		}
		else
		{
			preTarget=target;
			target=target->next;
		}
	}
	printf("没找到要删除的数据");

}


void Reverse(ListNode *&pHead)
{
	assert(pHead);//应该是需要进行检查的
	ListNode *newpHead=NULL;
	ListNode *tmp=NULL,*cur=pHead;
	while(cur)
	{
		tmp=cur;//摘取
		cur=cur->next;
		
		tmp->next=newpHead;
		newpHead=tmp;
		
	}
	pHead=newpHead;
}


void Loop(ListNode *pHead)
{
	ListNode *cur=pHead;
	while(cur->next!=NULL)
	{
		cur=cur->next;
	}
	cur->next=pHead;
}







void Joseph(ListNode *pHead,ListNode *StartNode,int x)
{
	ListNode *tmp=NULL;
	ListNode *cur=pHead;
	while(cur->next!=cur)
	{
		for(int i=0;i<x-1;i++)
		{
			cur=cur->next;
		}//指针先进行后移
		tmp=cur->next;//tmp就是要删除的节点
		cur->next=tmp->next;
		printf("将要删除的是%d\n",tmp->_data);
		free(tmp);//当删除到最后一个节点的时候应该怎么让cur变空
	}
}//删的只剩下最后一个节点

void InsertNonHead(ListNode *pos,DataType x)
{
	assert(pos);
	ListNode *tmp=BuyNode(pos->_data);
	pos->_data=x;
	ListNode *next=pos->next;
	pos->next=tmp;
	tmp->next=next;
}



//void my_Bubble_Sort(ListNode *pHead)//1.删除再插入  我的版本
//{
//	ListNode *i,*j;
//	for(i=pHead;i!=NULL;i=i->next)
//	{
//		for(j=pHead;j->next!=NULL;j=j->next)
//		{
//			if(j->_data<j->next->_data)
//			{
//				InsertNonHead(j,j->next->_data);
//				Erase(pHead,j->next->next);
//			}
//		}
//	}
//}//这样的冒泡排序也许会有问题



void Bubble_Sort(ListNode *pHead)//老师的版本
{
	ListNode *tail=NULL;
	ListNode *prev=pHead,*cur=pHead;
	while(tail!=pHead)
	{
		while(cur!=tail)
		{
			if(prev->_data<cur->_data)
			{
				DataType tmp=prev->_data;
				prev->_data=cur->_data;
				cur->_data=tmp;
			}
		}
		tail=prev;
	}
}



void Select_Sort(ListNode *pHead)//2.改变指针指向
{
	ListNode *i,*j;
	for(i=pHead;i->next!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(i->_data<j->_data)
			{

			}
		}
	}
}


ListNode* HaveCircle(ListNode *pHead)//采用快慢指针的方法判断，返回值是环中快慢指针相遇的某点
{
	if(NULL == pHead)
	{
		printf("The list is Empty");
		return NULL;
	}
	ListNode *slow=pHead,*fast=pHead;
	while(fast && fast->next)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast == slow)
		{
			return slow;
		}
	}
	return NULL;
}



ListNode *GetEntryNode(ListNode *pHead,ListNode *pos)
{
	ListNode *slow=pHead,*fast=pos;
	while(slow!=fast)
	{
		slow=slow->next;
		fast=fast->next; 
	}
	return slow;
}

int GetLength(ListNode *pos)//这个函数是用来求环的长度的，传入的参数是判断是否有环的时候返回的相遇的节点就成
{
	assert(pos);
	ListNode *cur=pos;
	int count=1;
	while(cur->next != pos)
	{
		count++;
		cur=cur->next;
	}
	return count;
}


//
//
//ListNode* HaveLoop(ListNode *pHead)//究竟有没有环？我自己想的方法
//{
//	if(NULL == pHead)
//	{
//		printf("The list is Empty");
//		return NULL;
//	}
//	ListNode *cur=pHead;
//	ListNode *i;
//	for(;cur;cur=cur->next)
//	{
//		for(i=pHead;i!=cur;i=i->next)
//		{
//			if(i==cur->next)
//			{
//				printf("在这里%d有环！！",cur->next->_data);
//				return cur->next;
//			}
//		}
//	}
//	return NULL;
//}
//
//size_t CountLoop(ListNode *pos)//计算环的长度
//{
//	int count=1;
//	assert(pos);
//	ListNode *cur=pos->next;
//	while(cur!=pos)
//	{
//		count++;
//		cur=cur->next;
//	}
//	return count;
//}



bool Isbanana_non(ListNode *pHeada,ListNode *pHeadb)//无环版本
{
	if(NULL == pHeada || NULL == pHeadb)
	{
		printf("链表为空，怎么可能相交");
		return false;
	}
	ListNode *cura=pHeada;
	ListNode *curb=pHeadb;
	while(cura->next)
	{
		cura=cura->next;
	}
	while(curb->next)
	{
		curb=curb->next;
	}
	if(cura==curb)
	{
		return true;
	}
	return false;
}



//ListNode *FindKNode(ListNode *pHead , size_t k)//寻找第K个节点
//{
//	ListNode *slow=pHead , *fast=pHead;
//	for(int i=0;i<k;i++)
//	{
//		if(NULL == fast)
//		{
//			printf("error : The number k is invalid ( The list is not long enough )");
//			return NULL;
//		}
//		fast=fast->next;
//		
//	}
//	while(fast)
//	{
//		slow=slow->next;
//		fast=fast->next;
//	}
//	return slow;
//}



bool HaveCross(ListNode *pHead1,ListNode *pHead2)
{
	ListNode *meetnode1=HaveCircle(pHead1);
	ListNode *meetnode2=HaveCircle(pHead2);
	if(meetnode1 ==NULL && meetnode2 == NULL)//两个都没环
	{
		if(Isbanana_non(pHead1,pHead2))
		{
			return true;
		}
	}
	else if(meetnode1 && meetnode2)//两个都有环(可能相交？)
	{
		ListNode *cur=meetnode1;
		while(cur!=meetnode1)
		{
			if(cur == meetnode2)
			{
				return true;
			}
			cur=cur->next;
		}
		return false;
	}
	else
	{
		return false;
	}
}





