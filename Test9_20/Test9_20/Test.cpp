#include<stdio.h>
#include<string.h>
//NO string 

void main()
{
	char ar[] = "";
	printf("%d\n",sizeof(ar));
	printf("%d\n",strlen(ar));
}

/*
void main()
{
	char *p = "abcdef";

	char ar[] = {'h','e','l','l','o'};
	printf("%d\n",sizeof(ar));
	printf("%d\n",strlen(ar));
}

/*
void main()
{
	char ar[10] = {'h','e','l','l','o'};
	printf("%d\n",sizeof(ar));
	printf("%d\n",strlen(ar));
}


void main()
{
	for(int i=3; i<=7; ++i)
	{
		printf("%c \n",i);
	}
}


void main()
{
	int br[10] = {1,2,3};
	br[0] = 10; //???
	0[br] = 100;
}


void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("%p\n",ar);
	printf("%p\n",&ar[0]);
	printf("%p\n",&ar);

	int *p = ar;
	int *q = &ar;
}


void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("size = %d\n",sizeof(ar));
}



void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};

	for(int i=0; i<10; ++i)
	{
		printf("%d  ",ar[i]);
	}
	printf("\n");

	for(i=0; i<10; ++i)
	{
		printf("%d  ",*(ar+i));
	}
	printf("\n");

	int *p = ar;
	for(i=0; i<10; ++i)
	{
		printf("%d  ",p[i]);
	}
	printf("\n");

	for(i=0; i<10; ++i)
	{
		printf("%d  ",*(p+i));
	}
	printf("\n");
}

/*
int br[10];

void main()
{
	//初始化
	int ar[10];

	//赋值
	for(int i=0; i<5; ++i)
	{
		ar[i] = i+1; //1 2 3 4 5
	}
}


void main()
{
	int a = 10;
	int c = 1000;
	{
		int b = 100;
		printf("b = %d\n",b);
	}
	//printf("b = %d\n",b);
	printf("a = %d\n",a);
}

/*
int br[10];

void main()
{
	//初始化
	int ar[10];

	//赋值
	for(int i=0; i<5; ++i)
	{
		ar[i] = i+1; //1 2 3 4 5
	}
}


void main()
{
	void * a; //泛型指针
}



#define MAX_SIZE 255

void main()
{
	unsigned char i = 0;
	for(;i <= MAX_SIZE; ++i)
	{
		printf("i = %d\n",i);
	}
}


void main()
{
	int a = -1;
	char ch = -128;
}

/*
void main()
{
	printf("%d\n",sizeof(char));
	printf("%d\n",sizeof(bool));
	printf("%d\n",sizeof(short));
	printf("%d\n",sizeof(int));
	printf("%d\n",sizeof(long));
	printf("%d\n",sizeof(float));
	printf("%d\n",sizeof(double));
	//printf("%d\n",sizeof(void));
}

/*
void main()
{

	int ar[10][10];
	int **p = ar;
	
}


void main()
{
	for(int i=0; i<10; ++i)
	{
		printf("%d \n",i);
	}

	int sum = 0;
}
*/
