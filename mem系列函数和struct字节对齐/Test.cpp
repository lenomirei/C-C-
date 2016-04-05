#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

//ÄÚ´æÐ¹Â¶

//void fun(int n)
//{
//	int *a;
//	a = (int *)malloc(sizeof(int)*n);
//	if(a == NULL)
//	{
//		printf("Error!\n");
//		exit(1);
//	}
//	for(int i=0; i<n; ++i)
//	{
//		a[i] = i;
//	}
//	free(a);
//}
//
//void main()
//{
//	int n;
//	scanf("%d",&n);
//	fun(n);
//}


//memcmp()
//memmove()

void* my_memcpy(void *dest, const void *src, size_t count)
{
	assert(dest!=NULL && src!=NULL);
	char *pdest = (char*)dest;
	const char *psrc = (const char*)src;
	
	if(psrc>=pdest || pdest>=psrc+count)
	{
		while(count-- > 0)
		{
			*pdest++ = *psrc++;
		}
	}
	else
	{	
		while(count-- > 0)
		{
			*(pdest+count)= *(psrc+count);
		}
	}
	return dest;
}
void main()
{
	char s1[] = "abcdefghij";
	memcpy(s1+2,s1,2);
	printf("s1 = %s\n",s1);
	//char *s2 = "abcdefghij";
	//my_memcpy(s2+2,s2, 4);
	//printf("s2 = %s\n",s2);
}

/*
void* my_memset(void *dest, int c, size_t count)
{
	assert(dest != NULL);
	char *pdest = (char *)dest; //-128 ~ 127
	while(count-- > 0)
	{
		*pdest++ = c;
	}
	return dest;
}

void main()
{
	int ar[10];
	char str[10];
	//my_memset(ar,0,10);
	my_memset(str,0,sizeof(char)*10);
}

/*
int my_strcmp(const char*strDest, const char*strSrc)
{
	assert(strDest!=NULL && strSrc!=NULL);
	if(*strDest=='\0' && *strSrc=='\0')
		return 0;
	const char *pDest = strDest;
	const char *pSrc = strSrc;

	int result = 0;
	while(*pDest!='\0' || *pSrc!='\0')
	{
		if((result=*pDest-*pSrc) != 0)
			break;
		pDest++;
		pSrc++;
	}
	return result;
}

void main()
{
	char s1[20] = "hello";
	char s2[] = "xello";

	int res = my_strcmp(s1,s2);
	printf("res = %d\n",res);
}

/*
int my_strcmp(const char*strDest, const char*strSrc)
{
	assert(strDest!=NULL && strSrc!=NULL);
	if(*strDest=='\0' && *strSrc=='\0')
		return 0;
	const char *pDest = strDest;
	const char *pSrc = strSrc;

	//abc  ab
	int result = 0;
	while(*pDest!='\0' || *pSrc!='\0')
	{
		if((result=*pDest-*pSrc) != 0)
			break;
		pDest++;
		pSrc++;
	}
	if(result > 0)
		result = 1;
	else if(result < 0)
		result = -1;
	return result;
}

void main()
{
	char s1[20] = "hello";
	char s2[] = "xello";

	int res = my_strcmp(s1,s2);
	printf("res = %d\n",res);
}

/*
//s1 > s2   1
//s1 == s2  0
//s1 < s2   -1

int my_strcmp(const char*strDest, const char*strSrc)
{
	assert(strDest!=NULL && strSrc!=NULL);
	if(*strDest=='\0' && *strSrc=='\0')
		return 0;
	const char *pDest = strDest;
	const char *pSrc = strSrc;

	int result = 0;
	//abc    ab
	while(*pDest!='\0' && *pSrc!='\0')
	{
		if(*pDest > *pSrc)
			return 1;
		else if(*pDest < *pSrc)
			return -1;
		pDest++;
		pSrc++;
	}
	if(*pDest != '\0')
		result = 1;
	else if(*pSrc != '\0')
		result = -1;
	return result;
}

void main()
{
	char s1[20] = "hello";
	char s2[] = "hello";

	int res = my_strcmp(s1,s2);
	printf("res = %d\n",res);
}
*/
//strcpy
/*
char* my_strcpy(char *strDest,const char *strSrc)
{
	assert(strDest!=NULL && strSrc!=NULL);
	char *pDest = strDest;
	const char *pSrc = strSrc;

	while(*pSrc != '\0')
	{
		*pDest++ = *pSrc++;
	}
	*pDest = '\0';
	return strDest;
}
int main()
{
	char str[20] = "helfjlafa";

	char str1[] = "world";
	my_strcpy(str,str1);
	printf("%s\n",str); //worldlafa
	return 0;
}

*/
/*
int main()
{
	char str[] = "hello world";
	puts(str);
	return 0;
}
*/
