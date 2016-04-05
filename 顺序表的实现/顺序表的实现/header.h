#include<memory.h>
#include<string.h>
#include<assert.h>


#define MAX_SIZE 100
typedef int DataType;


typedef struct List
{
	DataType arr[MAX_SIZE];
	int size;
}Seqlist;


void PrintList(Seqlist *pSeq)
{
	int i=0;
	for(i=0;i<pSeq->size;i++)
	{
		printf("%3d",pSeq->arr[i]);
	}
	printf("\n");
}



void IniSeqlist(Seqlist *pSeq)
{
	assert(pSeq);
	memset(pSeq->arr,0,sizeof(DataType)*MAX_SIZE);
	pSeq->size=0;
}

void PopHead(Seqlist *pSeq)
{
	int index=0;
	assert(pSeq);
	if(pSeq->size <= 0)
	{
		printf("error:The list is Empty!");
		return ;
	}
	for( ;index+1<pSeq->size ; index++)//index+1<size
	{
		pSeq->arr[index]=pSeq->arr[index+1];
	}
	pSeq->size--;
}//ͷɾ

void PopEnd(Seqlist *pSeq)
{
	assert(pSeq);
	if(pSeq->size<=0)
	{
		printf("error:The list is Empty!");
		return ;
	}
	pSeq->arr[pSeq->size-1]=0;//��仰����û�У�ֱ�ӶԳɶ�����--�Ϳ��Լ�������ĳ���
	pSeq->size--;
}//βɾ

void PushHead(Seqlist *pSeq , DataType n)
{
	int index=pSeq->size;
	assert(pSeq);
	if(pSeq->size >= MAX_SIZE)
	{
		printf("error:The list if Full!");
	}
	//���б��ͷ�������ݲ�����Ҫ�������ݸ��ǵ����⣬����ķ����Ǵ����ʼŲ������
	for(;index>0;index--)
	{
		pSeq->arr[index]=pSeq->arr[index-1];
	}
	pSeq->arr[0]=n;
	pSeq->size++;
}//ͷ��


void PushEnd(Seqlist *pSeq , DataType n)
{
	assert(pSeq);
	if(pSeq->size >= MAX_SIZE)
	{
		printf("error:The list if Full!");
	}
	pSeq->arr[pSeq->size]=n;
	pSeq->size++;
}//β��


void  Insert(Seqlist *pSeq , size_t pos , DataType n)
{
	int index=pSeq->size;
	assert(pSeq);
	if(pSeq->size >= MAX_SIZE)
	{
		printf("error:The list is Full!");
	}
	if(pos > pSeq->size)
	{
		printf("error:The pos is Overflow!");
	}
	for( ; index>pos ; index--)
	{
		pSeq->arr[index]=pSeq->arr[index-1];
	}
	pSeq->arr[pos]=n;
	pSeq->size++;
}

void del(Seqlist *pSeq , size_t pos)
{
	int index=pos;
	assert(pSeq);
	if(pSeq->size <= 0)
	{
		printf("error:The list is Empty!");
	}
	if(pos > pSeq->size)
	{
		printf("error:The pos is Overflow");
	}
	for( ; index <= pSeq->size ; index++)
	{
		pSeq->arr[index]=pSeq->arr[index+1];
	}
	pSeq->size--;
	pSeq->arr[pSeq->size]=0;//��仰���Բ��ӣ�ԭ���βɾ����
}


void Remove(Seqlist *pSeq , DataType deldata)//����Ҫɾ��������
{
	int i,flag=0;//����һ��flag���������Ƿ���ҵ�Ҫɾ�����������ǲ��ҵ�������Ϊ1��û���ҵ���Ϊ0
	assert(pSeq);
	if(pSeq->size <= 0)
	{
		printf("error:The list is Empty!");
	}
	for(i=0;i<pSeq->size;i++)
	{
		if(deldata == pSeq->arr[i])
		{
			flag=1;//���ҵ�������ݣ����λ��Ϊ1
			del(pSeq,i);
			return ;
		}
	}
	if(flag==0)
	{
		printf("û���ҵ�Ҫɾ��������");
	}
}//������Ŀ����ɾ����һ��ƥ�䵽����


void RemoveAll(Seqlist *pSeq , DataType deldata)
{
	int i,flag=0;//����һ��flag���������Ƿ���ҵ�Ҫɾ�����������ǲ��ҵ�������Ϊ1��û���ҵ���Ϊ0
	assert(pSeq);
	if(pSeq->size <= 0)
	{
		printf("error:The list is Empty!");

	}
	for(i=0;i<pSeq->size;i++)
	{
		if(deldata == pSeq->arr[i])
		{
			flag=1;//���ҵ�������ݣ����λ��Ϊ1
			del(pSeq,i);
			i--;//д��仰����ҪĿ���Ƿ�ֹ������������Ҫɾ��������Ϊִ�й�del����֮�����������±�-1��ͬʱi+1�����ܻ���
			continue;
		}
	}
	if(flag==0)
	{
		printf("û���ҵ�Ҫɾ��������");
	}
}

void BubbleSort(Seqlist *pSeq)
{
	int i,j;
	int temp;
	for ( i=0 ; i<(pSeq->size-1) ; i++ )
	{
		for ( j=0 ; j<(pSeq->size-1-i) ; j++ )
		{
			if(pSeq->arr[j]>=pSeq->arr[j+1])
			{
				/*pSeq->arr[i]=pSeq->arr[i]+pSeq->arr[i+1];
				pSeq->arr[i+1]=pSeq->arr[i]-pSeq->arr[i+1];
				pSeq->arr[i]=pSeq->arr[i]-pSeq->arr[i+1];*/
				temp=pSeq->arr[j];
				pSeq->arr[j]=pSeq->arr[j+1];
				pSeq->arr[j+1]=temp;
			}
		}
	}

}