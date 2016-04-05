#include<stdio.h>
#include<string.h>
#include<assert.h>

//∂œ—‘
//‘§—‘

char *my_strcat(char *Dest,const char *Src)
{
	assert(Dest!=NULL && Src!=NULL);

	char *pDest = Dest;
	const char *pSrc = Src;

	while(*pDest++ != '\0');
	pDest--;
	while(*pSrc != '\0')
	{
		*pDest++ = *pSrc++;
	}
	*pDest = '\0';
	return Dest;
}

void main()
{
	char *p = NULL;
	char str[20] = "hello";
	char *str1 = "world";
	printf("str = %s\n",str);
	p = my_strcat(str,str1);
	printf("str = %s\n",str);
	printf("str = %s\n",p);
}


/*
size_t my_strlen(const char *string)
{
	assert(string != NULL);
	if(*string == '\0')
		return 0;
	return my_strlen(string+1)+1;
}

void main()
{
	char *str = "abcde"; 
	int length = my_strlen(str);
	printf("length = %d\n",length);
}

/*

size_t my_strlen(const char *string)
{
	assert(string != NULL);
	const char *ptmp = string; //1

	for(size_t i=0; *ptmp++!='\0';++i);
	return i;
}

void main()
{
	char *str = "abcde"; 
	int length = my_strlen(str);
	printf("length = %d\n",length);
}


/*
size_t my_strlen(const char *string)
{
	assert(string != NULL);
	size_t count = 0;

	while(*string++ != '\0')  // 0
	{
		count++;
	}
	return count;
}

void main()
{
	char *str = "abcde"; 
	int length = my_strlen(str);
	printf("length = %d\n",length);
}


/*
void main()
{
	char str[20] = "xello";
	char *str1 = "xello";
	int length = strlen(str);

	//strcat(str,str1);
	//printf("%s\n",str);

	//strcpy(str,str1);
	//printf("%s\n",str);

	int res = strcmp(str,str1); //a < b -1
								//a == b 0
								//a > b 1

}


int Max(int a, int b)
{
	return a>b?a:b;
}

int Max(int a, int b, int c)
{
	//return (a>b?a:b) > c ? (a>b?a:b) : c;
	return Max(Max(a,b),c);
}

double Max(double a, double b)
{
	return a>b?a:b;
}

void main()
{	
	Max(10,20);
}


#include<stdio.h>

typedef int Ar[10]; //int[10]
typedef int(*PFUN)(int,int); //PFUN pfun

int Max(int a, int b)
{
	return a>b?a:b;
}
int Min(int a, int b)
{
	return a<b?a:b;
}

PFUN fun(int x, int y, PFUN pfun)
{
	int result = pfun(x,y);
	return pfun; //int(*)(int,int)
}

void main()
{
	PFUN  p; //int(*p)(int,int);
	//p = fun(10,20,Max);
	p = &Max;

	int a = 0;
	int *q;
	q = &a;
}

/*
void main()
{
	int a,b;
	while(1)
	{
		printf("Please input a and b:>");
		scanf("%d,%d",&a, &b);
		fun(a,b,Min);
		//printf("result = %d\n",result);
	}
}

/*
void main()
{
	char str[] = "hello";
	char *str1 = "world";

	str[0] ='H';
	str1[0] = 'W';
}



//∫Í∂®“Â
#define PCHAR char*
typedef char* PCHAR1;

void main()
{
	char str[] = "hello";

	const PCHAR pc1 = str; //
	const PCHAR1 pc2 = str;
	//const char *pc1 = str;
	//const char *pc2 = str;   char* const p;
	//*pc1 = 'H';
	*pc2 = 'H';

	pc1++;
	//pc2++;
}

/*
void main()
{
	char ch = 'A';
	PCHAR1 ch1,ch2; //char*  ch1, ch2;
	ch1 = &ch;
	ch2 = &ch;
}


void main()
{
	char ch = 'A';
	PCHAR ch1,ch2; //char *;ch1, ch2;
	ch1 = &ch;
	ch2 = ch;
}
*/