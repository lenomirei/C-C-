#include<assert.h>
#include<memory.h>
#include<malloc.h>
//ð��������Ż�������ʱ�����ж�   removeall�������Ż�������ָ��
//ѡ���Ż���ѡ��һ�˵�������Сֵ
//���ֲ��ң��͵ݹ�ʵ�ֶ��ֲ���
typedef int DataType;
typedef struct SeqList
{
	DataType *array;
	size_t size;//��Ч������
	size_t capicity;//����
}SeqList;


void CheckCapicity(SeqList *pSeq)
{
	DataType *tmp;
	assert(pSeq);
	if(pSeq->size >= pSeq->capicity)
	{
		pSeq->capicity=pSeq->capicity*2;
		
		tmp=(DataType *)malloc(pSeq->capicity);
		memcpy(tmp,pSeq->array,pSeq->size);
		pSeq->array=tmp;
	}
}


void IniSeqList(SeqList *pSeq)
{
	assert(pSeq);
	pSeq->capicity=3;
	pSeq->size=0;
	pSeq->array=(DataType *)malloc(sizeof(DataType)*pSeq->capicity);
}


void PrintList(SeqList *pSeq)
{
	assert(pSeq);
	int i=0;
	for(i=0;i<pSeq->size;i++)
	{
		printf("%3d",pSeq->array[i]);
	}
	printf("\n");
}


void PushBack(SeqList *pSeq , DataType x)
{
	CheckCapicity(pSeq);
	pSeq->array[pSeq->size]=x;
	pSeq->size++;
}


void PushFront(SeqList *pSeq , DataType x)
{
	CheckCapicity(pSeq);
	int index=pSeq->size;
	for(;index>0;index--)
	{
		pSeq->array[index]=pSeq->array[index-1];
	}
	pSeq->array[0]=x;
	pSeq->size++;
}


void PopBack(SeqList *pSeq)
{
	assert(pSeq);
	if(pSeq->size <= 0)
	{
		printf("The list is Empty!!");
		return ;
	}
	pSeq->size--;
}

void PopFront(SeqList *pSeq)
{
	assert(pSeq);
	if(pSeq->size <= 0)
	{
		printf("The list is Empty!!");
		return ;
	}

	int index=0;
	for( ;index+1<pSeq->size ; index++)//index+1<size
	{
		pSeq->array[index]=pSeq->array[index+1];
	}
	pSeq->size--;
}



void RemoveAll(SeqList *pSeq,DataType x)
{
	assert(pSeq);
	if(pSeq->size<=0)
	{
		printf("error:The list is Empty");
		return ;
	}
	int first=0;
	int second=0;
	while(second<pSeq->size)
	{
		if(pSeq->array[second]!=x)
		{
			first=second;
		}
		else
		{
			pSeq->size--;
		}
		second++;
	}
}//��first��second����ָ��ȥʵ���Ƴ�����һ��������secondֻҪ����Ҫɾ�������ݾͺ�first��ֵ����



void Bubble_Sort(SeqList *pSeq)
{
	assert(pSeq);
	int i,j;
	int temp;
	
	for ( i=0 ; i<(pSeq->size-1) ; i++ )
	{
		int exchange=0;
		for ( j=0 ; j<(pSeq->size-1-i) ; j++ )
		{
			if(pSeq->array[j]>=pSeq->array[j+1])
			{
				exchange++;
				/*pSeq->array[i]=pSeq->array[i]+pSeq->array[i+1];
				pSeq->array[i+1]=pSeq->array[i]-pSeq->array[i+1];
				pSeq->array[i]=pSeq->array[i]-pSeq->array[i+1];*/
				temp=pSeq->array[j];
				pSeq->array[j]=pSeq->array[j+1];
				pSeq->array[j+1]=temp;
			}
		}
		if(exchange == 0)
		{
			break;
		}
	}
}


void Select_Sort(SeqList *pSeq)
{
	assert(pSeq);
	int min;
	int max;
	for(int i=0;i<pSeq->size;i++)
	{
		min=i;
		max=pSeq->size-i;
		for(int j=i+1;j<pSeq->size;j++)
		{
			if(pSeq->array[min]>pSeq->array[j])
			{
				min=j;
			}
			if(pSeq->array[max]<pSeq->array[j])
			{
				max=j;
			}
		}
		pSeq->array[i]=pSeq->array[min];
		pSeq->array[pSeq->size-i]=pSeq->array[max];
	}
}//��������һ�����һ����С


int BinarySearch(SeqList *pSeq,DataType x)
{
	assert(pSeq);
	int left=0;
	int right=pSeq->size-1;
	int mid;
	while(left<=right)
	{
		mid=left+(right-left)/2;
		if(x>pSeq->array[mid])
		{
			left=mid+1;
		}
		else if(x<pSeq->array[mid])
		{
			right=mid-1;
		}
		else
		{
			return mid;
		}
	}
	printf("û�ҵ�");
	return -1;

}



int BinarySearch_s(SeqList *pSeq,int left,int right,DataType x)//������������
{
	assert(pSeq);
	int mid;
	mid=left+(right-left)/2;
	if(left<0 || right>pSeq->size-1)
	{
		printf("error :input invalid");
		return -1;
	}
	if(left >right)
	{
		printf("û�ҵ�");
		return -1;
	}
	
	if(x<pSeq->array[mid])
	{
		return BinarySearch_s(pSeq,left,mid-1,x);
	}
	else if(x>pSeq->array[mid])
	{
		return BinarySearch_s(pSeq,mid+1,left,x);
	}
	else
	{
		return mid;
	}
}