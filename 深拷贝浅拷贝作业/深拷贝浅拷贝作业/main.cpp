#include"head.h"


void test()
{
	String s1("cello world");
	String s2("hello world");
	String s3("hello world");
	String s4("change world");
	String s5("hello worldd");
	if( s1 <= s2 )
	{
		cout<<"Ð¡ÓÚÅ¶"<<endl;
	}
	if(s2>s5)
	{
		cout<<"success"<<endl;
	}
	if(s2==s3)
	{
		cout<<"equal"<<endl;
	}
}

void test1()

{

}


void test2()
{
	String s1("hehe");
	String s2("haha");
	s2=s1;
}
void test3()
{
	String s1("heihei");
	String s2(s1);
}
int main()
{
	/*test();*/
	
	test3();
	return 0;
}
