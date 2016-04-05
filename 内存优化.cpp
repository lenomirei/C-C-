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
	B b2 = fun(b1);//发生优化，编译器会自动对返回值进行优化，按理说应该会产生一个临时变量来存放返回值，但是由于（诶呀吗这么多临时变量要弄死我了），然后编译器就优化了
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