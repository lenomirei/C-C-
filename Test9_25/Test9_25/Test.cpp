#include<iostream>
#include<stdio.h>
using namespace std;
/*
(*((void(*)())0))()

int (*func)(int *, int (*)(int *));
//
int (*func[5])(int *);
//
int (*(*func)[5])(int *);
//
int (*(*func)(int *)) [5];
//
int*(*func(int*))[5]




�ñ���a��������Ķ���
a) һ��������
  int a; 
b) һ��ָ����������ָ��
  int *a;

c) һ��ָ��ָ���ָ�룬��ָ���ָ����ָ��һ��������
      int **a;

d) һ����10��������������
     int a[10];

e) һ����10��ָ������飬��ָ����ָ��һ���������ġ�
     int *a[10];

f) һ��ָ����10�������������ָ��
    int(*a)[10]

g) һ��ָ������ָ�룬�ú�����һ�����Ͳ���������һ��������
    int(*a)(int);

h) һ����10��ָ������飬��ָ��ָ��һ��������
   �ú�����һ�����Ͳ���������һ��������

   int(*a[10])(int);
   */
int Max(int a, int b)
{
	return a>b?a:b;
}

void main()
{
	int ar[10];
	int (*p)[10] = &ar;//ָ��10��intԪ�����飨һ���������ͣ�����ָ��
	printf("%p\n",p);
	printf("%p\n",++p);

	int (*pfun)(int,int);
	pfun = Max;
	//pfun++;

}
/*

int Max(int a, int b)
{
	return a>b?a:b;
}

void main()
{
	int a = 10;
	int *p = &a;
	p++;

	int(*pfun)(int,int);
	pfun = Max;
	pfun++;

	int ar[10];
	ar++;
}

/*
void Swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void main(int argc, char *argv[])
{
}


void Swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void main()
{
	int a = 10;  //2147483647
	int b = 20;
	printf("Before a = %d, b = %d\n",a,b);
	Swap(&a,&b);
	printf("After a = %d, b = %d\n",a,b);
}


void main()
{
	int a = 10;
	int &b = a;
}

/*
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void main()
{
	int a = 10;
	int b = 20;
	printf("Before a = %d, b = %d\n",a,b);
	Swap(a,b);
	printf("After a = %d, b = %d\n",a,b);
}

/*
void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void main()
{
	int a = 10;
	int b = 20;
	printf("Before a = %d, b = %d\n",a,b);
	Swap(&a,&b);
	printf("After a = %d, b = %d\n",a,b);
}

/*
void Swap(int *a, int *b)
{
	int *temp = a;
	a = b;
	b = temp;
}

void main()
{
	int a = 10;
	int b = 20;
	printf("Before a = %d, b = %d\n",a,b);
	Swap(&a,&b);
	printf("After a = %d, b = %d\n",a,b);
}

/*
void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void main()
{
	int a = 10;
	int b = 20;
	printf("Before a = %d, b = %d\n",a,b);
	Swap(a,b);
	printf("After a = %d, b = %d\n",a,b);
}

/*
int Max(int a, int b)
{
	return a>b?a:b;
}

double* fun(int ar[])
{}

void main()
{
	//int(*pfun)(int,int);
	int ar[3] = {1,2,3};
}

/*
void main()
{
	printf("Max value = %d\n",Max(10,20));

	int(*pfun)(int,int);

	pfun = &Max;
	printf("Max value = %d\n",(*pfun)(100,200));

	pfun = Max;
	printf("Max value = %d\n",pfun(1,2));
}

/*
//����ָ��

void main()
{
	int ar[3] = {10,20,30};
	int(*p)[5] = &ar;

	int a,b,c;
	a = 10;
	b = 20;
	c = 30;
	int *br[3];
	br[0] = &a;
	br[1] = &b;
	br[2] = &c;
}

/*
void main()
{
	printf("Max value = %d\n",Max(10,20));
}

/*
void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("%d\n",sizeof(ar));
	printf("%s\n",typeid(ar).name());
	printf("%d\n",sizeof(&ar));
	printf("%s\n",typeid(&ar).name());
}


void main()
{
	double a = 10;
	printf("%s\n",typeid(a).name());
}


void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("%p\n",sizeof(ar));
	printf("%s\n",typeid(ar).name());
	printf("%p\n",sizeof(&ar));
	printf("%s\n",typeid(&ar).name());
}


void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	//printf("%d\n",sizeof(ar));
	printf("%p\n",&ar[0]);
	printf("%p\n",ar);
	printf("%p\n",&ar);

	int *p = &ar[0];
	int *q = ar;
	//int *t = &ar;
	int (*t)[10] = &ar;
}

/*
void main()
{
	int a = 10;
	char *pc = (char*)&a;
	printf("%p : %p\n",pc,pc+1);
	short *ps = (short*)&a;
	printf("%p : %p\n",ps,ps+1);
	int *pi = &a;
	printf("%p : %p\n",pi,pi+1);
	double *pd = (double*)&a;
	printf("%p : %p\n",pd,pd+1);
}
*/