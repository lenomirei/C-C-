#include <stdio.h>
#include <windows.h>
//����Ĳ�������   ת�������ֳ���int���ͷ�Χ������� ͷ����������
//����Ҫ���м��������������Ĳ���Ҫ�Ǵ���ľͲ��ܷ�����Чֵ
#define MAXINT 0x7fffffff
#define MININT 0x80000000

enum status
{
	leagal=0,
	illeagal
};

int str_to_int(char *str,status *s)
{

}


int str_to_int_core(char *str,status *s,int symbol)


void main()
{

}



//#define MAX_INT 0x7ffffffff
//#define MIN_INT 0x800000000
//
//typedef enum Status
//{
//	legal=0,
//	illegal,
//}status_t;
//
//
//int str_to_int_core(char *str , status_t *s , int symbol)
//{
//	long long num=0;
//	while(*str!='\0')
//	{
//		if(*str<'0'||*str>'9')
//		{
//			*s=illegal;
//			return 0;
//		}
//		else
//		{
//			num=num*10+symbol*(*str-'0');//��������һֱʹ��ǿ��ת����һֱ��������
//			str++;
//		}
//	}
//	if((symbol == 1 && num > MAX_INT) || (symbol == -1 && num < (signed int)MIN_INT))
//	{
//		*s=illegal;
//		return 0;
//	}
//	return (int)num;
//}
//
//
//
//int str_to_int(char *str,status_t *s)
//{
//	if(NULL == str || *str == '\0' || NULL == s)
//	{
//		*s=illegal;
//		return 0;
//	}//����©����һЩ����û�п���ô��
//	int symbol=1;
//	if(*s == '-')
//	{
//		symbol=-1;
//		str++;
//	}
//	else if(*s == '+')
//	{
//		str++;
//	}
//	else
//	{}
//	return str_to_int_core(str ,s ,symbol);
//}
//void main()
//{
//	char t1[]="10000000000000000";
//	status_t status=legal;
//	int result=str_to_int(t1,&status);
//	if(status==illegal)
//	{
//		printf("error code :%d",result);
//	}
//	else
//	{
//		printf("%d",result);
//	}
//}






/*
//ONE
void right_loop_right(char *p_str, unsigned short steps)
{
	int index = strlen(p_str) - 1;
	steps %= (index + 1);//д��仰����ҪĿ�ľ���Ϊ�������������ַ������ܳ��Ȼ�Ҫ������
	while (steps){
		char tmp = p_str[index];
		int count = index;
		while (count){
			p_str[count] = p_str[count-1];
			count--;

		}
		p_str[count] = tmp;
		steps--;
	}
}
*/
/*
void reverse(char *start, char *end)
{
	if (NULL == start || NULL == end){
		return;
	}
	end--;
	char tmp;
	while (start < end){
		tmp = *end;
		*end = *start;
		*start = tmp;
		start++;
		end--;
	}
}

//TWO
void right_loop_right(char *p_str, unsigned short steps)
{
	int len = strlen(p_str);
	steps %= len;
	reverse(p_str, p_str + len - steps);
	reverse(p_str + len - steps, p_str + len);
	reverse(p_str, p_str + len);
}

int main()
{
	char target_str[] = "abc123";
	int i = 0;
	while (i < 100){
		right_loop_right(target_str, 1);
		printf("%s\n", target_str);
		Sleep(1000);
		i++;
	}
	system("pause");
	return 0;
}
*/
/*
void show_bit(unsigned char bit_8)
{
	int i = 0;
	unsigned char flag = 0x80; //1000 0000
	for (; i < sizeof(unsigned char)* 8; i++){
		if (flag & bit_8){
			printf("1");
		}
		else{
			printf("0");
		}
		flag >>= 1;
	}
	printf("\n");
}

#define _ZERO_ 0//for flag
#define _ONE_  1
void bit_set(unsigned char *p_data, unsigned char pos, int flag)
{
	if (flag == _ZERO_)
	{
		*p_data &= ~(0x1 << pos);
	}
	else if (flag == _ONE_)
	{
		*p_data |= (0x1 << pos);
	}
	else
	{
		return;
	}
}

int main()
{
	unsigned char tmp = 0x0f;
	show_bit(tmp);
	bit_set(&tmp, 7, _ONE_);
	show_bit(tmp);
	bit_set(&tmp, 0, _ZERO_);
	show_bit(tmp);
	system("pause");
	return 0;
}*/


/*
//ONE
int str_to_int(char *int_str)
{
	int num = 0;
	while (*int_str != '\0'){
		num = num * 10 + (*int_str - '0');
		int_str++;
	}
	return num;
}

//TWO
#define MAX_INT 0x7FFFFFFF
#define MIN_INT 0x80000000

typedef enum status{
VALID=0,
INVALID,
}status_t;

int str_to_int(char *int_str, status_t *s)
{
*s = VALID;
if (NULL == int_str || *int_str == '\0' || \
NULL == s){
*s = INVALID;
return 1;
}
long long num = 0;
while (*int_str != '\0'){
if (*int_str >= '0' && *int_str <= '9'){
num = num * 10 + (*int_str - '0');
}
else{
*s = INVALID;
return 2;
}
int_str++;
}
//if (num > MAX_INT || num < MIN_INT){//bug?
//	printf("num is overflow!\n");
//  *s = INVALID;
//	return 3;
//}
return (int)num;
}

*/
//THREE FOUR








//д���������Ҫ����һЩ����
//����Ĳ�������   ת�������ֳ���int���ͷ�Χ������� ͷ����������
//#define MAX_INT 0x7FFFFFFF
//#define MIN_INT 0x80000000
//
//typedef enum status{
//	VALID=0,
//	INVALID,
//}status_t;
//
//int str_to_int_core(char *int_str, status_t *s, int symbol)//�����symbol�Ǵ������ķ���
//{
//	long long num = 0;
//	while (*int_str != '\0'){
//		if (*int_str >= '0' && *int_str <= '9'){
//			num = num * 10 + symbol*(*int_str - '0');
//		}
//		else{
//			*s = INVALID;
//			return 2;
//		}
//		int_str++;
//	}
//	if ( (symbol == 1 && num > MAX_INT) || \
//		(symbol == -1 && num < (signed int)MIN_INT)){
//		printf("num is overflow!\n");
//		*s = INVALID;
//		return 3;
//	}
//	return (int)num;
//}
//int str_to_int(char *int_str, status_t *s)
//{
//	*s = VALID;
//	if (NULL == int_str || *int_str == '\0' || NULL == s){
//		*s = INVALID;
//		return 1;
//	}
//	int  symbol = 1;
//	if (*int_str == '+'){
//		int_str++;
//	}
//	else if (*int_str == '-'){
//		symbol = -1;
//		int_str++;
//	}
//	else{
//		//DO NOTHING
//	}
//	return str_to_int_core(int_str, s, symbol);
//
//}
//
//int main()
//{
//	char int_str[] = "-123456";
//	status_t s;
//	int ret_int = str_to_int(int_str, &s);
//	if (s == VALID){
//		printf("result int : %d\n", ret_int);
//	}
//	else{
//		printf("errno code : %d\n", ret_int);
//	}
//	system("pause");
//	return 0;
//}
