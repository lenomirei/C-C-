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
}//头删

void PopEnd(Seqlist *pSeq)
{
	assert(pSeq);
	if(pSeq->size<=0)
	{
		printf("error:The list is Empty!");
		return ;
	}
	pSeq->arr[pSeq->size-1]=0;//这句话可以没有，直接对成都进行--就可以剪短数组的长度
	pSeq->size--;
}//尾删

void PushHead(Seqlist *pSeq , DataType n)
{
	int index=pSeq->size;
	assert(pSeq);
	if(pSeq->size >= MAX_SIZE)
	{
		printf("error:The list if Full!");
	}
	//在列表的头进行数据插入需要考虑数据覆盖的问题，解决的方法是从最后开始挪动数据
	for(;index>0;index--)
	{
		pSeq->arr[index]=pSeq->arr[index-1];
	}
	pSeq->arr[0]=n;
	pSeq->size++;
}//头插


void PushEnd(Seqlist *pSeq , DataType n)
{
	assert(pSeq);
	if(pSeq->size >= MAX_SIZE)
	{
		printf("error:The list if Full!");
	}
	pSeq->arr[pSeq->size]=n;
	pSeq->size++;
}//尾插


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
	pSeq->arr[pSeq->size]=0;//这句话可以不加，原理和尾删类似
}


void Remove(Seqlist *pSeq , DataType deldata)//给出要删除的数据
{
	int i,flag=0;//设置一个flag变量来看是否查找到要删除的数据若是查找到了则设为1，没查找到设为0
	assert(pSeq);
	if(pSeq->size <= 0)
	{
		printf("error:The list is Empty!");
	}
	for(i=0;i<pSeq->size;i++)
	{
		if(deldata == pSeq->arr[i])
		{
			flag=1;//查找到相关数据，标记位设为1
			del(pSeq,i);
			return ;
		}
	}
	if(flag==0)
	{
		printf("没有找到要删除的数据");
	}
}//函数的目标是删除第一个匹配到的数


void RemoveAll(Seqlist *pSeq , DataType deldata)
{
	int i,flag=0;//设置一个flag变量来看是否查找到要删除的数据若是查找到了则设为1，没查找到设为0
	assert(pSeq);
	if(pSeq->size <= 0)
	{
		printf("error:The list is Empty!");

	}
	for(i=0;i<pSeq->size;i++)
	{
		if(deldata == pSeq->arr[i])
		{
			flag=1;//查找到相关数据，标记位设为1
			del(pSeq,i);
			i--;//写这句话的主要目的是防止连续出现两个要删除的数因为执行过del函数之后，数据整体下标-1，同时i+1，可能会错过
			continue;
		}
	}
	if(flag==0)
	{
		printf("没有找到要删除的数据");
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