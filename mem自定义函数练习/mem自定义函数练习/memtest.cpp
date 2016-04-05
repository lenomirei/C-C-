//mem系列函数的编写与熟练
//那么要编写的mem函数一共有哪几个呢？
//memset memcpy memmove memcmp  realloc  

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<memory.h>



//void* my_memcpy(void *dest, const void *src, size_t count)
//{
//	assert(dest!=NULL && src!=NULL);
//	char *pdest=(char *)dest;
//	char *psrc=(char *)src;
//	if(pdest<=psrc ||pdest>=psrc+count)
//	{
//		while(count-->0)
//		{
//			*pdest++=*psrc++;
//		}
//	}
//	else
//	{
//		while(count-->0)
//		{
//			*(pdest+count)=*(psrc+count);
//		}
//	}
//	return dest;
//}
//
//void main()
//{
//	char t1[]="adahuf";
//	char t2[]="abcdefg";
//	printf("%s\n",t1);
//	my_memcpy(t1+1,t1,3);//考虑情况自身copy自身
//	printf("%s\n",t1);
//}







//void* my_memset(void *dest, int c, size_t count)
//{
//	assert(dest);
//	char *pdest=(char *)dest;
//	while(count-->0)
//	{
//		*pdest++=c;
//	}
//	return dest;
//}
//
//void main()
//{
//	int ar[10];
//	my_memset(ar,0,sizeof(int)*10);
//}