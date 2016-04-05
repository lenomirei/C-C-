#include<stdio.h>
#include<string.h>
#include<assert.h>



#define MININT 0x7fffffff
#define MAXINT 0x80000000

typedef enum Status
{
	legal = 0,
	illegal
}status_t;


int str_to_int_core(char *str,status_t *s,int  symbol)
{
	long long num = 0;
	while (*str != '/0')
	{
		if (*str<'0' || *str>'9')
		{
			*s = illegal;
			return -1;
		}
		else
		{
			num = num * 10 + symbol*(*str - '0');
			str++;
		}
	}
	if ((symbol == 1 && num > MAXINT) || (symbol == -1 && num < MININT))
	{
		*s = illegal;
		return -1;
	}
	return (int)num;
}


int str_to_int(char *str ,status_t *s)
{
	if (NULL == str || NULL == s || *str == '/0')
	{
		*s = illegal;
		return -1;
	}
	int symbol = 0;
	if (*str == '-')
	{
		symbol = -1;
		str++;
	}
	else if(*str=='+')
	{
		symbol = 1;
		str++;
	}
	else
	{
	}
	return str_to_int_core(str, s, symbol);
}




int mian()
{
	char *shu = "124732";
	status_t s = legal;
	printf("%d", str_to_int(shu, &s));
	return 0;
}