#include<iostream>
#include<windows.h>
using namespace std;


int main()
{
	WIN32_FIND_DATAA p;
	char *tmp = "*.*";
	HANDLE h = FindFirstFileA(tmp, &p);
	cout << p.cFileName << endl;
	while (FindNextFileA(h,&p))
	{
		cout << p.cFileName << endl;
	}
	return 0;
}
