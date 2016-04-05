#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<math.h>
#include<malloc.h>


//第一题
//int main()
//{
//	printf("hello world");
//	return 0;
//}

//第二题

//int main()
//{
//	int result = 0;
//	for (int i = 0; i < 100 / 2; i++)
//	{
//		result += 1 + 100;
//	}
//	printf("%d", result);
//	return 0;
//}



//第三题

//int main()
//{
//	for (int i = 1; i < 10; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %d", i, j, i*j);
//			printf("   ");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//第四题

//int Bigger(int a,int b)
//{
//	if (a >= b)
//	{
//		return a;
//	}
//	else
//	{
//		return b;
//	}
//}
//
//
//int main()
//{
//	int a = 1, b = 2;
//	printf("%d", Bigger(a, b));
//
//	return 0;
//}


//第五题


//int WhoIsBigest(int *arr)
//{
//	assert(arr);
//	int biggest = arr[0];
//	for (int i = 0; i < 10; i++)
//	{
//		if (biggest < arr[i])
//		{
//			biggest = arr[i];
//		}
//	}
//	return biggest;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d", WhoIsBigest(arr));
//	return 0;
//}

//第六题
//int main()
//{
//	for (int i = 1; i <= 100; i++)
//	{
//		
//	}
//	return 0;
//}


//第七题

//求解最大公约数有两种算法，一种是辗转相除，另一种是更相减损术
//int GYS(int a, int b)
//{
//	int yushu = 0;
//	if (a < b)
//	{
//		a = a + b;
//		b = a - b;
//		a = a - b;
//	}
//	while (b != yushu)
//	{
//		yushu = a - b;
//		a = b;
//		b = yushu;
//	}
//	return yushu;
//}
//int main()
//{
//	int a = 24, b = 32;
//	printf("%d", GYS(a, b));
//	return 0;
//}



//第八题
//int GBS(int a, int b)
//{
//	int yushu = 0;
//	if (a < b)
//	{
//		a = a + b;
//		b = a - b;
//		a = a - b;
//	}
//	while (b != yushu)
//	{
//		yushu = a - b;
//		a = b;
//		b = yushu;
//	}
//	return (a*b)/yushu;
//}
//int main()
//{
//	int a = 24, b = 32;
//	printf("%d", GBS(a, b));
//	return 0;
//}

//第九题

//int main()
//{
//	int a = 1, b = 2;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	return 0;
//}
//


//第十题

//void Swap(int *a, int *b)
//{
//	int t;
//	t = *a;
//	*a = *b;
//	*b = t;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	Swap(&a, &b);
//	return 0;
//}

//第十一题
//1,2,3,4四个数字组成互不相同且无重复数字的三位数
//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 4; i++)
//	{
//		for (int j = 1; j <= 4; j++)
//		{
//			if (j == i)
//			{
//				continue;
//			}
//			for (int k = 1; k <= 4; k++)
//			{
//				if (k == i || k == j)
//				{
//					continue;
//				}
//				count++;
//				printf("%d\n", 100 * i + 10 * j + k);
//			}
//		}
//	}
//	return 0;
//}


//第十二题

//int main()
//{
//	int yearcount = 0;
//	for (int i = 0; i < 2001; i++)
//	{
//		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
//		{
//			yearcount++;
//			printf("%d", i);
//		}
//	}
//	return 0;
//}


//第十三题


//int main()
//{
//	float fenzi = 2, fenmu = 1;
//	float result = 0;
//	for (int i = 0; i < 20; i++)
//	{
//		result += fenzi / fenmu;
//		float t = fenzi;
//		fenzi = fenzi + fenmu;
//		fenmu = t;
//	}
//	return 0;
//}



//第十四题

//int main()
//{
//	int a, n;
//	printf("输入a和n");
//	scanf("%d%d", &a, &n);
//	int result = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int t = 0;
//		for (int j = 0; j <= i; j++)
//		{
//			t += a*pow(10, j);
//		}
//
//		result += t;
//	}
//	return 0;
//}

//第十五题

//
//int main()
//{
//	float result = 0, height = 100;
//	for (int i = 0; i < 10; i++)
//	{
//		result += height;
//		height = height / 2;
//		result += height;
//	}
//	printf("第十次落下的距离是:%d 总共经过的距离是:%d", height, result);
//	return 0;
//}

//第十六题!!!!

//int main()
//{
//	int result = 1;
//	for (int i = 0; i < 10; i++)
//	{
//		result += 1;
//		result = result * 2;
//	}
//	return 0;
//}


//第十七题
//int main()
//{
//	float result = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		result += 1 / i;
//	}
//	return 0;
//}


//第十八题
//
//int main()
//{
//	int result = 0;
//	for (int i = 1; i <= 20; i++)
//	{
//		int t = 1;
//		for (int j = i; j > 0; j--)
//		{
//			t *= j;
//		}
//		result += t;
//	}
//
//}



//第十九题!!!!!!

//判断一个数是否是回文数


//char *int_to_string(int a)
//{
//	int i;
//	int t = a;
//	char *result=(char *)malloc(sizeof(char)*10);
//	for (i = 0; t >= 1; i++)
//	{
//		result[i]=t%(int )(pow(10, i));
//		t = t / pow(10, i);
//	}
//	result[i] = '\0';
//	return result;
//}
//
//
//int main()
//{
//	int a = 1221;
//	printf("%s",int_to_string(a));
//	return 0;
//}

//第二十题
//判断回文字符串


//bool judge(char *a)
//{
//	for (int i = 0; i < strlen(a); i++)
//	{
//		if (a[i] != a[strlen(a) - i - 1])
//		{
//			return false;
//		}
//	}
//
//	return true;
//}
//
//
//int main()
//{
//	char *result = "heeh";
//	if (judge(result))
//	{
//		printf("yes");
//	}
//	else
//	{
//		printf("no");
//	}
//	return 0;
//}


//第二十一题

//int main()
//{
//	int result = 0;
//	int matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	for (int i = 0; i < 3; i++)
//	{
//		result += matrix[i][i];
//		result += matrix[i][3 - i];
//	}
//	result -= matrix[2][2];
//}


//第二十二题
//数组的逆序


//void Reverse(int *a, int n)
//{
//	n--;
//	for (int i = 0; i <= n - i; i++)
//	{
//		int t = a[i];
//		a[i] = a[n - i];
//		a[n - i] = t;
//	}
//}
//
//int main()
//{
//	int a[5] = { 1,2,4,5,6 };
//	printf("原先的数组");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d", a[i]);
//	}
//	Reverse(a, 5);
//	printf("逆序之后的数组");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d", a[i]);
//	}
//	return 0;
//}




//第二十三题


//void main()
//{
//	int a[10] = { 1,5,7,8,94,2,4,3,9,10 };
//	printf("原先的数组\n");
//	for (int i = 0; i<10; i++)
//	{
//		printf("%3d", a[i]);
//	}
//	printf("\n");
//	int temp;
//	for (int i = 0; i<10; i++)
//	{
//		for (int j = 0; j<i; j++)
//		{
//			if (a[i] <= a[j])
//			{
//				temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//	printf("排序后的数组\n");
//	for (int i = 0; i<10; i++)
//	{
//		printf("%3d", a[i]);
//	}
//}

//第二十四题

//int main()
//{
//	char *test[3] = { "bit-tech","world","hello" };
//	char *temp;
//	printf("原来的字符串顺序\n");
//	for (int i = 0; i<3; i++)
//	{
//		printf("%s\n", test[i]);
//	}
//	for (int i = 0; i<3; i++)
//	{
//		for (int j = 0; j<i; j++)
//		{
//			if (strcmp(test[i], test[j]) == -1)
//			{
//				temp = test[i];
//				test[i] = test[j];
//				test[j] = temp;
//			}
//		}
//	}
//	printf("排序后的字符串顺序\n");
//	for (int i = 0; i<3; i++)
//	{
//		printf("%s\n", test[i]);
//	}
//	return 0;
//}


//第二十五题
//用递归求斐波那契数列的第N个数
//斐波那契数列11235

//
//int feibonqi(int n)
//{
//	if (n == 0) return(0);
//	else if (n == 1) return(1);
//	else
//		return(feibonqi(n - 1) + feibonqi(n - 2));
//}
//main()
//{
//	int n, s;
//	scanf("%d", &n);
//	s = feibonqi(n);
//	printf("%d\n", s);
//}