#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<math.h>
#include<malloc.h>


//��һ��
//int main()
//{
//	printf("hello world");
//	return 0;
//}

//�ڶ���

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



//������

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


//������

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


//������


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

//������
//int main()
//{
//	for (int i = 1; i <= 100; i++)
//	{
//		
//	}
//	return 0;
//}


//������

//������Լ���������㷨��һ����շת�������һ���Ǹ��������
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



//�ڰ���
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

//�ھ���

//int main()
//{
//	int a = 1, b = 2;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	return 0;
//}
//


//��ʮ��

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

//��ʮһ��
//1,2,3,4�ĸ�������ɻ�����ͬ�����ظ����ֵ���λ��
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


//��ʮ����

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


//��ʮ����


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



//��ʮ����

//int main()
//{
//	int a, n;
//	printf("����a��n");
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

//��ʮ����

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
//	printf("��ʮ�����µľ�����:%d �ܹ������ľ�����:%d", height, result);
//	return 0;
//}

//��ʮ����!!!!

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


//��ʮ����
//int main()
//{
//	float result = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		result += 1 / i;
//	}
//	return 0;
//}


//��ʮ����
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



//��ʮ����!!!!!!

//�ж�һ�����Ƿ��ǻ�����


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

//�ڶ�ʮ��
//�жϻ����ַ���


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


//�ڶ�ʮһ��

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


//�ڶ�ʮ����
//���������


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
//	printf("ԭ�ȵ�����");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d", a[i]);
//	}
//	Reverse(a, 5);
//	printf("����֮�������");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d", a[i]);
//	}
//	return 0;
//}




//�ڶ�ʮ����


//void main()
//{
//	int a[10] = { 1,5,7,8,94,2,4,3,9,10 };
//	printf("ԭ�ȵ�����\n");
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
//	printf("����������\n");
//	for (int i = 0; i<10; i++)
//	{
//		printf("%3d", a[i]);
//	}
//}

//�ڶ�ʮ����

//int main()
//{
//	char *test[3] = { "bit-tech","world","hello" };
//	char *temp;
//	printf("ԭ�����ַ���˳��\n");
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
//	printf("�������ַ���˳��\n");
//	for (int i = 0; i<3; i++)
//	{
//		printf("%s\n", test[i]);
//	}
//	return 0;
//}


//�ڶ�ʮ����
//�õݹ���쳲��������еĵ�N����
//쳲���������11235

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