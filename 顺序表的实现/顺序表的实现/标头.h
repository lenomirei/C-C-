#include<string.h>
#include<assert.h>
#include<memory.h>
#include<stdio.h>

typedef int DataType;

#define MAXSIZE 100


typedef struct seqlist
{
	DataType _array[MAXSIZE];
	size_t _size;
}SeqList;



void IniSeqList(SeqList *s)
{
	assert(s);
	memset(s->_array, 0, sizeof(DataType)*MAXSIZE);
	s->_size = 0;
}

//PushBack  PushFront PopBack PopFront PrintList  Insert del  Bubblesort SelectSort BinarySearch 
//���׺���Remove RemoveAll Reverse


void PrintList(SeqList *s)
{
	assert(s);
	for (int i = 0; i < s->_size; i++)
	{
		printf("%d", s->_array[i]);
	}
	printf("\n");
}

void PushBack(SeqList* s, DataType x)
{
	assert(s);
	if (s->_size > MAXSIZE)
	{
		printf("error:���������������");
		return ;
	}
	s->_array[s->_size] = x;
	s->_size++;
}

void PushFront(SeqList *s, DataType x)
{
	assert(s);
	size_t index = s->_size;
	if (s->_size > MAXSIZE)
	{
		printf("error:���������������");
		return ;
	}
	for (int i = index; i > 0; i--)
	{
		s->_array[i] = s->_array[i - 1];
	}
	s->_array[0] = x;
	s->_size++;
}

void PopBack(SeqList *s)
{
	assert(s);
	if (s->_size <= 0)
	{
		printf("error:û�������ˣ�");
		return;
	}
	s->_array[s->_size - 1] = 0;
	s->_size--;
}

void PopFront(SeqList *s)
{
	assert(s);
	if (s->_size <= 0)
	{
		printf("error:û�������ˣ�");
		return;
	}
	for (int i = 0; i < s->_size; i++)
	{
		s->_array[i] = s->_array[i + 1];
	}
	s->_size--;
	s->_array[s->_size] = 0;
}

void Insert(SeqList *s, size_t pos, DataType x)
{
	assert(s);
	size_t index = s->_size;
	if (pos > s->_size || pos < 0)
	{
		printf("����δ֪���Ϸ�������Χ");
		return;
	}
	if (s->_size >= MAXSIZE)
	{
		printf("�������ݴ洢��С");
		return;
	}
	for (; index > pos; index--)
	{
		s->_array[index] = s->_array[index - 1];
	}
	s->_array[pos] = x;
	s->_size++;
}

void del(SeqList *s, size_t pos)
{
	assert(s);
	if (s->_size <= 0)
	{
		printf("û�������ˣ������ٳ���");
		return;
	}
	size_t index = pos;
	for (; index < s->_size; index++)
	{
		s->_array[index] = s->_array[index + 1];
	}
	s->_size--;
	s->_array[s->_size] = 0;
}