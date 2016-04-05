#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
#define ROW 3
#define COL 3

void main()
{//如何使用malloc开辟一个二维数组空间
	int i;
	int **p = (int**)malloc(sizeof(int *) * ROW);
	for(int i=0; i<ROW; ++i)
	{
		p[i] = (int *)malloc(sizeof(int) * COL);
	}

	for(i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			p[i][j] = i+j;
		}
	}

	for(i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
  for(i=0;i<ROW;i++)
  {
	  free(p[i]);
	  
  }
  free(p);
	
}
/*
enum {A,B,C};
enum e{X=-100,Y,Z};
void main()
{
	//A
	//B
	//C
	//sizeof(e);
}

/*
union Test
{
	char a;
	int b;
	double d;
};

void main()
{
	Test t;
	t.d = 12.34;
	t.b = 100;
    
}


/*
struct Test
{
	int a;
	double e;
	int b;
};

void main()
{
	Test ar[3] = {{1,1.1,2}, {3,3.3,4}, {5,5.5,6}};
}

/*
void main()
{
	Test t = {10,20,12.34};
	Test *pt = (Test *)malloc(sizeof(Test));
	pt->a = 100;
	pt->b = 200;
	pt->e = 23.45;

}


/*
struct A 
	{
		int c;
		int d;
	};
struct Test
{
	int a;
	int b;
	A   aa;
	double e;
};

void main()
{
	Test t;
}

/*
struct Date
{
	int year;
	int month;
	int day;
};
struct Time
{
	int hour;
	int mintue;
	int second;
};

struct B
{
	Date date;  //int a;
	Time time;  //int b
};

void main()
{
	B b;
	b.date.year = 1900;
	b.date.month = 10;
	b.date.day = 10;
}


struct Test
	int a;
	double b;
	char c;
}t1,t2;

void main()
{
	t1 tt;
	tt.a  =10;
}

/*
struct Student
{
	char id[5];
	char name[10];
	int age;
	char sex[3];
};

void main()
{
	Student s1 = {"0001","败家娘么",22,"女"};
	printf("id = %s\n",s1.id);
	printf("name = %s\n",s1.name);
	printf("age = %d\n",s1.age);
	printf("sex = %s\n",s1.sex);

	Student s2;
	strcpy(s2.id,"0002");
	strcpy(s2.name,"发了");
	s2.age = 20;
	strcpy(s2.sex,"男");
}


#define ROW 3
#define COL 3

void main()
{
	int **p = (int**)malloc(sizeof(int *) * ROW);
	for(int i=0; i<ROW; ++i)
	{
		p[i] = (int *)malloc(sizeof(int) * COL);
	}

	for(i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			p[i][j] = i+j;
		}
	}

	for(i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}

	//free
	//
}

/*
void main()
{
	int ar[10] = {0};
	int *pa = (int*)malloc(sizeof(int)*10);
	memset(pa,0,sizeof(int)*10);

	ar[0] = 1;
	*(ar+1) = 2;

	pa[0] = 1;
	pa[1] = 2;
}

/*
void main()
{
	int a = 10;

	int *p = (int*)_alloca(sizeof(int)*10);
	
}


void main()
{
	int *p = (int *)malloc(sizeof(int) * 10);
	//int *q = p;
	free(p); // 野指针
	p = NULL;
	if(NULL == p)
	{
		printf("OK!\n");
	}

}


#define SIZE 5
#define Type int

void* my_realloc(void *p, size_t size)
{
	//1
	void* new_p = malloc(size);
	if(NULL == new_p)
	{
		exit(1);
	}
	//2
	memcpy(new_p,p,size);
	//3
	free(p);
	//4
	return new_p;
}

void main()
{
	Type *p;
	p = (Type*)malloc(sizeof(Type) * SIZE);
	//p = (Type*)calloc(SIZE,sizeof(Type));

	if(NULL == p)
	{
		printf("out of memory!\n");
		exit(1);
	}
	for(int i=0; i<SIZE; ++i)
	{
		p[i] = i+1;
	}

	for(i=0; i<SIZE; ++i)
	{
		printf("%d ",p[i]);
	}
	printf("\n");

	p = (int*)my_realloc(p,sizeof(Type)*2*SIZE);
	for(i=5; i<2*SIZE; ++i)
	{
		p[i] = i+1;
	}
	for(i=0; i<2*SIZE; ++i)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
	free(p);
}
*/