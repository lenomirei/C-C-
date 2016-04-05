#include<iostream>
#include<stdio.h>
//struct student 
//{ 
//	char name[5];
//	short sex;        
//	int num;          
//	
//};
//int main()
//{
//	printf("%d\n",sizeof(struct student));
//	return 0;
//}
#include<assert.h>

//void _assert(void *exp, void *file, unsigned int line)
//{
//	printf("Assert failed: %s\n",exp);
//	printf("File: %s\n",file);
//	printf("Line: %d\n",line);
//	abort();
//}
//
////#  ##
//
//#define assert(exp) (void)( (exp) || (_assert(#exp, __FILE__, __LINE__),0) )//exp就是expression（表达式）的意思
//
//
//void main()
//{
//	int a = 0;
//	assert(a != 0);
//	printf("OK!\n");
//}


void main()
{
	std::cout<<__FILE__<<std::endl;
	std::cout<<__LINE__<<std::endl;
	std::cout<<__DATE__<<std::endl;
	std::cout<<__TIME__<<std::endl;
}

/*
#define Max(a,b)  (((a)>(b))?(a):(b))

#define Add(a,b)  ((a)+(b))
#define Mul(a,b)  ((a)*(b))

void main()
{
	//    ((5)+(6)) * ((7)+(8))
	//cout<<Add(5,6)*Add(7,8)<<endl;
	//       2+3 * 4+5
	//cout<<Mul(2+3,4+5)<<endl;
}

/*
#pragma pack(4)

int main()
{
	unsigned char puc[4];
	struct tagPIM
	{
		unsigned char ucPim1;
		unsigned char ucData0 : 1;
		unsigned char ucData1 : 2;
		unsigned char ucData2 : 3;
	}*pstPimData;
	
	pstPimData = (struct tagPIM*)puc;
	
	memset(puc,0,4);
	pstPimData->ucPim1 = 2;
	pstPimData->ucData0 = 3;
	pstPimData->ucData1 = 4;
	pstPimData->ucData2 = 5;
	
	printf("%02x %02x %02x %02x\n",puc[0],puc[1],puc[2],puc[3]);
	//     
	return 0;
}
#pragma pack() /*恢复缺省对齐方式*/


/*

#pragma pack(4)

union tagAAAA
{
	struct
	{
		char ucFirst;
		short usSecond;
		char ucThird;
	}half;
	short kk;
}number;

struct tagBBBB
{
	char ucFirst;
	short usSecond;
	char ucThird;
	short usForth;
}half;

struct tagCCCC
{
	struct
	{
		char ucFirst; //1+1
		short usSecond;//2
		char ucThird; //1+1
	}half;
	long kk;  //4+2
};
void main()
{
	cout<<sizeof(union tagAAAA)<<endl;
	cout<<sizeof(struct tagBBBB)<<endl;
	cout<<sizeof(struct tagCCCC)<<endl;
}


/*
typedef struct Test
{
	short a; // 2+2
	double b;// 8
}Test;
void main()
{
	cout<<sizeof(Test)<<endl;
}

/*
#pragma pack(4)

struct tagAAA
{
		unsigned char ucld : 1;
		unsigned char ucPara0 : 2;
		unsigned char ucState : 6;
		unsigned char ucTail : 4;
		unsigned char ucAvail;     //1
		unsigned char ucTail2 : 4;
		unsigned char ucData;
}AAA_S;

void main()
{
	cout<<sizeof(AAA_S)<<endl; //
}

/*
#pragma pack(4)

unsigned short *pucCharArray[10][10];

typedef union unRec
{
	unsigned long ullndex;   //4
	unsigned short usLevel[7];//2*7
	unsigned char ucPos;     //1
}REC_S;

REC_S stMax, *pstMax;

void main()
{
	cout<<sizeof(pucCharArray)<<endl;  //400
    cout<<sizeof(stMax)<<endl;         //16
    cout<<sizeof(pstMax)<<endl;        //4
	cout<<sizeof(*pstMax)<<endl;       //16
}

/*
typedef struct Test
{
	double a;
	char   c;
	int    b;
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
}


/*
//位域

typedef struct Test
{
	char a : w7;
	int  b : 12;
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
}

/*

typedef struct Test
{
	char a : 3; // 0 1
	char b : 4;
	char c : 2;
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
}

/*
//32//40//32

//哑成员

typedef struct Test
{
	short a;           //2 + 6
	struct A
	{
		int b;         //4 + 4
		double c;      //8 
		char d;        //1 + 7
	};
	long e;            //4 + 4
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
	Test t;
	t.a = 10;
	t.e = 100;
}

/*

typedef struct Test
{
	short a;           //2 + 2
	struct 
	{
		int b;         //4 
		double c;      //8
		char d;        //1 + 3
	};
	long e;           //4 
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
	Test t;
	t.a = 'a';
	t.b = 12.34;
	t.c = 10;
	t.d = 20;
	t.e = 100;
}

/*

//28 //33//24 //32 //48 //40

typedef struct Test
{
	char a;           //1 + 7
	struct 
	{
		double b;     //8 
		int c;        //4 
		short d;      //2 + 2
	};
	long e;           //4 + 4
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
	Test t;
	t.a = 'a';
	t.b = 12.34;
	t.c = 10;
	t.d = 20;
	t.e = 100;
}

/*
//0

typedef struct Test
{
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
}
/*
typedef struct Test
{
	char a;   //1 + 1
	int c;    //4
	double b; //8
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
}

/*
#pragma pack(1)

typedef struct Test
{
	char a;   //1
	int c;    //4
	double b; //8
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
}

/*

typedef struct Test
{
	char a;   //1+3
	double b; //8
	int c;    //4
}Test;


void main()
{
	printf("size = %d\n",sizeof(Test));
	Test t;
	t.a = 'A';
	t.b = 12.34;
	t.c = 10;
}

/*
typedef struct Test
{
	char a;   //1
	int  b;   //4
	double c; //8
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
	Test t;
	t.a = 'A';
	t.c = 12.34;
	t.b = 10;
	
}

/*

typedef struct Test
{
	char a;   //1+7
	double c; //8
	int  b;   //4 + 4
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
	Test t;
	t.a = 'A';
	t.c = 12.34;
	t.b = 10;
	
}

/*
typedef struct Test
{
	char a;   //1 + 3
	int  b;   //4
	double c; //8
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
	Test t;
	t.a = 'A';
	t.b = 10;
	t.c = 12.34;
}
/*
typedef struct Test
{
	char a; //1
	char b; //1
	char c; //1
}Test;

void main()
{
	printf("size = %d\n",sizeof(Test));
}

/*

enum{A=-100,B,C=3};

enum{M=100};

void main()
{
	switch(s)
	{
	case M:
		break;
		case 
	}

	printf("A = %d\n",A);
	printf("B = %d\n",B);
	printf("C = %d\n",C);
}
*/