
#include<stdio.h>
#include<assert.h>

//将字符串转换成int数的最终版本


#define MAXINT 0x7fffffff
#define MININT 0x80000000



typedef enum st
{
	valid = 0,
	invalid
}status;




int str_to_int_core(char const *str, status *s, int signal)
{
	long long int result = 0;
	while (*str != '\0')
	{
		if (*str<'0' || *str>'9')
		{
			*s = invalid;
			return -1;
		}
		else
		{
			result = result * 10 + (*str - '0');
			str++;
		}
	}
	if ((signal == -1 && result<MININT) || (signal == 1 && result>MAXINT))
	{
		*s = invalid;
		return -1;
	}
	return (int)result;
}


int str_to_int(char const *str, status *s)
{
	int signal = 1;
	if (NULL == str || NULL == s)
	{
		*s = invalid;
		return -1;
	}
	if (*str == '-')
	{
		signal = -1;
		str++;
	}
	else if(*str=='+')
	{
		str++;
	}
	return str_to_int_core(str, s, signal);
}

int main()
{
	char *str = "12488217";
	status s = valid;
	printf("%d", str_to_int(str, &s));
	return 0;
}