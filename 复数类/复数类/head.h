#include<iostream>
using namespace std;

class Complex
{
public :
	Complex(double real,double image):_real(real),_image(_image)
	{

	}
	Complex(Complex& c)
	{
		_real=c._real;
		_image=c._image;
	}
	Complex operator=(Complex c);
	Complex operator+(Complex c);
	Complex operator-(Complex c);
	Complex operator++();
	Complex operator++(int);
	Complex operator--();
	Complex operator--(int);
	Complex operator+=(Complex c);
	Complex operator-=(Complex c);
	bool operator==(Complex c);
private:
	int _real;
	int _image;
};

Complex Complex::operator=(Complex c)
{
	_real=c._real;
	_image=c._image;
	return *this;
}


Complex Complex::operator+(Complex c)
{
	Complex tmp=*this;
	tmp._real=_real+c._real;
	tmp._image=_image+c._image;
	return tmp;
}
Complex Complex::operator+=(Complex c)
{
	
	_real=_real+c._real;
	_image=_image+c._image;
	return *this;
}

Complex Complex::operator-(Complex c)
{
	Complex tmp=*this;
	tmp._real=_real-c._real;
	tmp._image=_image-c._image;
	return tmp;
}
Complex Complex::operator-=(Complex c)
{
	
	_real=_real-c._real;
	_image=_image-c._image;
	return *this;
}

Complex Complex::operator++()
{
	_real=_real+1;
	_image=_image+1;
	return *this;
}
Complex Complex::operator--()
{
	_real=_real-1;
	_image=_image-1;
	return *this;
}


Complex Complex::operator++(int)
{
	Complex tmp=*this;
	_real=_real+1;
	_image=_image+1;
	return tmp;
}
Complex Complex::operator--(int)
{
	Complex tmp=*this;
	_real=_real-1;
	_image=_image-1;
	return tmp;
}
bool Complex::operator==(Complex c)
{
	return _real==c._real && _image==c._image;
}