#include<stdio.h>
#include<string.h>

void main()
{
	int i = '\6'; 
	printf("%d\n",i);
}

/*
//strlen()
//sizeof()

//指针数组
//数组指针

//指针函数
//函数指针

void main()
{
	char *str1[10];
	printf("size = %d\n",sizeof(str1)); //6
}

/*
void fun(char str1[])
{
	printf("len = %d\n", strlen(str1)); //5
	printf("size = %d\n",sizeof(str1)); //
}

void main()
{
	char str1[] = "hellojflajflalfjalfjlajl";
	printf("len = %d\n", strlen(str1)); //5
	printf("size = %d\n",sizeof(str1)); //6

	fun(str1);
}

/*
void main()
{
	char *str1 = "hello";
	printf("len = %d\n", strlen(str1)); //5
	printf("size = %d\n",sizeof(str1)); //4
}

/*


void main()
{
	char str1[10];
	printf("len = %d\n",strlen(str1)); //0
	printf("size = %d\n",sizeof(str1));//10
}

/*

void main()
{
	char str1[10];
	for(int i=0; i<5; ++i)
	{
		str1[i] = 'A'+i; //A B C D E
	}
	str1[i] = '0';
	printf("len = %d\n",strlen(str1)); //
	printf("size = %d\n",sizeof(str1));//
}

/*
void main()
{
	char ch = '\6';
}

/*
void main()
{
	char str1[10] = {'h','e','l','l','l','o',0}; //NULL
	printf("len = %d\n",strlen(str1)); //
	printf("size = %d\n",sizeof(str1));//10
}

/*
void main()
{
	char str1[] = {'h','e','l','l','o'};
	printf("len = %d\n",strlen(str1)); //
	printf("size = %d\n",sizeof(str1));//
}

/*
void main()
{
	char str1[] = "hello";
	printf("len = %d\n",strlen(str1)); //6
	printf("size = %d\n",sizeof(str1));//5
}

/*
//for()
//while()
//do{}while()

void main()
{

	for(int i=0; i<10; ++i)
	{
		if(i == 5)
			continue; //break
		printf("i = %d\n",i);
	}

}


/*
void main()
{
	int j = 0;
	while(j < 10)
	{
		for(int i=0; i<10; ++i)
		{
			if(i == 5)
				break;
			printf("i = %d\n",i);
		}
		j++;
	}
}

/*
void fun()
{
	for(int i=1; i<=9; ++i)
	{
		for(int j=1; j<=i; ++j)
		{
			printf("%d*%d = %d ",i,j,i*j);
		}
		printf("\n");
	}
}

void main()
{
	fun();
}

/*

void main()
{
	for(int i=0; i<10; ++i)//
	{
		printf("i= %d\n",i);
	}

	i = 0;
	while(i<10)
	{
		printf("i= %d\n",i);
		i++;
	}

	i = 0;
	do
	{
		printf("i = %d\n",i);
		i++;
	}while(i<10);

}

/*
bool IsLeap(int year)
{
	return ((year%4==0&&year%100!=0) || (year%400==0));
}

int GetDayByYM(int year, int month)
{
	int m[13] = {29,31,28,31,30,31,30,31,31,30,31,30,31};

	if(month == 2)
	{
		if(IsLeap(year))
			month = 0;
	}
	return m[month];
}

void main()
{
	int year;
	int month;
	printf("input year and month:>");
	scanf("%d,%d",&year,&month);
	int day = GetDayByYM(year,month);

	printf("day = %d\n",day);
}

/*
bool IsLeap(int year)
{
	return ((year%4==0&&year%100!=0) || (year%400==0));
}

int GetDayByYM(int year, int month)
{
	int m1[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int m2[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if(month == 2)
	{
		if(IsLeap(year))
			return m1[month-1];
		else
			return m2[month-1];
	}
	return m1[month-1];
}

void main()
{
	int year;
	int month;
	printf("input year and month:>");
	scanf("%d,%d",&year,&month);
	int day = GetDayByYM(year,month);

	printf("day = %d\n",day);
}

/*
bool IsLeap(int year)
{
	return ((year%4==0&&year%100!=0) || (year%400==0));
}

int GetDayByYM(int year, int month)
{
	int day;
	if(month==1||month==3||)
	return day;
}

void main()
{
	int year;
	int month;
	printf("input year and month:>");
	scanf("%d,%d",&year,&month);
	int day = GetDayByYM(year,month);

	printf("day = %d\n",day);
}

/*
bool IsLeap(int year)
{
	return ((year%4==0&&year%100!=0) || (year%400==0));
}

int GetDayByYM(int year, int month)
{
	int day;
	switch(month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		day = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = 30;
		break;
	case 2:
		{
			if(IsLeap(year))
			{
				day = 29;
			}
			else
			{
				day = 28;
			}
		}
		break;
	}
	return day;
}

void main()
{
	int year;
	int month;
	printf("input year and month:>");
	scanf("%d,%d",&year,&month);
	int day = GetDayByYM(year,month);

	printf("day = %d\n",day);
}

/*
bool IsLeap(int year)
{
	return ((year%4==0&&year%100!=0) || (year%400==0));
}

int GetDayByYM(int year, int month)
{
	int day;
	switch(month)
	{
	case 1:
		day = 31;
		break;
	case 3:
		day = 31;
		break;
	case 4:
		day = 30;
		break;
	case 5:
		day = 31;
		break;
	case 6:
		day = 30;
		break;
	case 7:
		day = 31;
		break;
	case 8:
		day = 31;
		break;
	case 9:
		day = 30;
		break;
	case 10:
		day = 31;
		break;
	case 11:
		day = 30;
		break;
	case 12:
		day = 31;
		break;
	case 2:
		{
			if(IsLeap(year))
			{
				day = 29;
			}
			else
			{
				day = 28;
			}
		}
		break;
	}
	return day;
}

void main()
{
	int year;
	int month;
	printf("input year and month:>");
	scanf("%d,%d",&year,&month);
	int day = GetDayByYM(year,month);

	printf("day = %d\n",day);
}

/*
void main()
{
	int select = 1; // 
	while(select)
	{
		printf("****************************\n");
		printf("* [1]  xxxxx     [2]  xxxxx*\n");
		printf("* [3]  xxxxx     [4]  xxxxx*\n");
		printf("* [5]  xxxxx     [6]  xxxxx*\n");
		printf("* [0]  Quit System!        *\n");
		printf("****************************\n");
		printf("请选择:>");
		scanf("%d",&select);
		if(select == 0)
			break;
		switch(select)
		{
		case 1:
			printf("Hello C\n"); //
			break;
		case 2:
			printf("Hello Linux\n");
			break;
		case 3:
			printf("Hello Java\n");
			break;
		default:
			printf("Input Error! again please!\n");
			break;
		}
	}
}


void main()
{
	int a = 10;
	int b = 20;

	int max = a>b?a:b;
}

/*
void main()
{
	int a = 1;
	int b = 1;

	int v = a || b++; //短路求值
	printf("v = %d\n",v);
	printf("b = %d\n",b);
}

/*
void main()
{
	int a = 10;
	int b = 20;
	//int v = a & b;
	//int v = a | b;  >> <<
	int v = ~a;
	printf("%d\n",v);
}


void main()
{
	int a = 0;
	int b = 20;
	//bool v = a && b; //true   false
	//bool v = a || b;
	bool v = !b;
	printf("%d\n",v);
}


void main()
{
	float d = 12.34f;

	bool a = true; //true
	if(a)  //
	{
		printf("Hello C\n");
	}
}


void main()
{
	int a;
	scanf("%d",&a);
	if(a > 100)
	{
		printf("Hello");
	}
	else if(a > 10)
	{

	}
	else if()
	{}
	else if()
	{}
	else
	{}


}

/*
void main()
{
	printf("  \"abcde\"  \n"); //转义
}


int main()
{
	int a,b;
	scanf("%d,%d",&a, &b); //1 2
	printf("a = %d, b = %d\n",a,b);
	return 0;
}
*/