#include<malloc.h>
#include<assert.h>




//insert ��������tmp������˳��
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



ListNode *Find(ListNode *pHead , DataType x)//pHeadû�иı䣬���Բ������ã���
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


void Insert(ListNode *pos , DataType x)//������������⣬��posָ�����һ���ڵ��ʱ�����Ϊ����NULL������
{
	assert(pos);
	ListNode *tmp=pos->next;
	pos->next=BuyNode(x);
	pos->next->next=tmp;
}


void PushBack(ListNode * &pHead , DataType x)//1.����Ϊ��2.����Ϊ��
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



void PushFront(ListNode *&pHead , DataType x)//1.����Ϊ��2.����Ϊ��
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
		pHead=tmp;//������pHead��Ҫ������
	}
}

void PopBack(ListNode *pHead)//1.����Ϊ��2.����ֻ��һ��Ԫ��3.���������Ԫ��
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


void PopFront(ListNode *&pHead)//1.����Ϊ��2.����ֻ��һ���ڵ�3.���������ڵ�
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
}//������ﲻ���������޷���ֵ




void Erase(ListNode *&pHead , ListNode *pos)//1.����Ϊ��2.����ֻ��һ��ֵ3.�����������ֵ
{//Ӧ�÷�Ϊ���������һ�����ҵ���pos��ͷ������һ��������ҵ���pos���������ͷ��
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




void Remove(ListNode *&pHead , DataType x)//1.��һ��Ҫɾ���Ľڵ����
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
	printf("û�ҵ�Ҫɾ��������");

}


void Reverse(ListNode *&pHead)
{
	assert(pHead);//Ӧ������Ҫ���м���
	ListNode *newpHead=NULL;
	ListNode *tmp=NULL,*cur=pHead;
	while(cur)
	{
		tmp=cur;//ժȡ
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
		}//ָ���Ƚ��к���
		tmp=cur->next;//tmp����Ҫɾ���Ľڵ�
		cur->next=tmp->next;
		printf("��Ҫɾ������%d\n",tmp->_data);
		free(tmp);//��ɾ�������һ���ڵ��ʱ��Ӧ����ô��cur���
	}
}//ɾ��ֻʣ�����һ���ڵ�

void InsertNonHead(ListNode *pos,DataType x)
{
	assert(pos);
	ListNode *tmp=BuyNode(pos->_data);
	pos->_data=x;
	ListNode *next=pos->next;
	pos->next=tmp;
	tmp->next=next;
}



//void my_Bubble_Sort(ListNode *pHead)//1.ɾ���ٲ���  �ҵİ汾
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
//}//������ð������Ҳ���������



void Bubble_Sort(ListNode *pHead)//��ʦ�İ汾
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



void Select_Sort(ListNode *pHead)//2.�ı�ָ��ָ��
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


ListNode* HaveCircle(ListNode *pHead)//���ÿ���ָ��ķ����жϣ�����ֵ�ǻ��п���ָ��������ĳ��
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

int GetLength(ListNode *pos)//��������������󻷵ĳ��ȵģ�����Ĳ������ж��Ƿ��л���ʱ�򷵻ص������Ľڵ�ͳ�
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
//ListNode* HaveLoop(ListNode *pHead)//������û�л������Լ���ķ���
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
//				printf("������%d�л�����",cur->next->_data);
//				return cur->next;
//			}
//		}
//	}
//	return NULL;
//}
//
//size_t CountLoop(ListNode *pos)//���㻷�ĳ���
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



bool Isbanana_non(ListNode *pHeada,ListNode *pHeadb)//�޻��汾
{
	if(NULL == pHeada || NULL == pHeadb)
	{
		printf("����Ϊ�գ���ô�����ཻ");
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



//ListNode *FindKNode(ListNode *pHead , size_t k)//Ѱ�ҵ�K���ڵ�
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
	if(meetnode1 ==NULL && meetnode2 == NULL)//������û��
	{
		if(Isbanana_non(pHead1,pHead2))
		{
			return true;
		}
	}
	else if(meetnode1 && meetnode2)//�������л�(�����ཻ��)
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





