#include<iostream>

using namespace std;



template<class T>
class class1
{
	T a;
};

template < class T, template<class> class class1 >
class class2
{
	T b;
	class1<T> c;
};



int main()
{
	return 0;
}