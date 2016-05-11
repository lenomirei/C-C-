#include<iostream>
#include<cassert>
using namespace std;


int my_strlen(const char * str)
{
	assert(str);
	int count = 0;
	const char *ptr = str;
	while (*(ptr++) != '\0')
	{
		count++;
	}
	return count;
}


int main()
{
	char *str = "hehe";
	cout << my_strlen(str) << endl;
	return 0;
}




#include<iostream>
#include<cassert>
using namespace std;

int _strlen_R(const char *str)
{
	assert(str);
	return my_strlen_R(str);
}

int my_strlen_R(const char *str)
{
	if (*str == '\0')
	{
		return 0;
	}
	return 1 + my_strlen_R(str + 1);
}



int main()
{
	char *str = "hehe";
	cout << my_strlen_R(str) << endl;
	return 0;
}



#include<iostream>
#include<cassert>
using namespace std;

char *my_strcpy(char *dest,const char *src)
{
	assert(dest && src);
	char *pdest = dest;
	const char *psrc = src;
	while (*psrc != '\0')
	{
		*(pdest++) = *(psrc++);
	}
	*pdest = '\0';
	return dest;
}



int main()
{
	char s1[] = "hahaha";
	char s2[] = "hao";
	cout << my_strcpy(s1, s2) << endl;
	return 0;
}



#include<iostream>
#include<cassert>
using namespace std;


char *my_strcat(char *dest,const char *src)
{
	assert(dest && src);
	char *pdest = dest;
	const char *psrc = src;
	while (*pdest != '\0')
	{
		pdest++;
	}
	while (*psrc != '\0')
	{
		*(pdest++) = *(psrc++);
	}
	*pdest = '\0';
	return dest;

}
int main()
{
	char s1[20] = "hello";
	char s2[] = "world";
	cout << my_strcat(s1, s2) << endl;
	return 0;
}



#include<iostream>
#include<cassert>
using namespace std;



int my_strcmp(const char *str1, const char *str2)
{
	assert(str1 && str2);
	const char *pstr1 = str1;
	const char *pstr2 = str2;
	while (*pstr1 != '\0'&& *pstr2 != '\0')
	{
		pstr1++;
		pstr2++;
	}
	if (*pstr1)
	{
		return 1;
	}
	if (*pstr2)
	{
		return -1;
	}
	return 0;
}


int main()
{
	char s1[] = "helloword";
	char s2[] = "helloword";
	cout << my_strcmp(s1, s2) << endl;
	return 0;
}