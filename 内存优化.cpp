#include<iostream>
using namespace std;
class B
{

};
B fun(const B& rhs)
{
	return ths;
}
int main()
{
	B b1;
	B b2 = fun(b1);//�����Ż������������Զ��Է���ֵ�����Ż�������˵Ӧ�û����һ����ʱ��������ŷ���ֵ���������ڣ���ѽ����ô����ʱ����ҪŪ�����ˣ���Ȼ����������Ż���
}


//class B
//{
//
//};
//B fun(const B& rhs)
//{
//	return rhs;
//}
//int main()
//{
//	B b1, b2;
//	b2 = func(b1);
//}