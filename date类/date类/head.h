#include<iostream>
#include<assert.h>
using namespace std;


class Date
{
public :
	Date(int year,int month,int day);
	Date(Date& d);
	Date operator +(int day);
	Date operator =(Date d);
	bool operator ==(Date d);
	Date operator -(int day);
	~Date();
private :

	int GetMonthDay(int year,int month);

	int _year;
	int _month;
	int _day;
};
Date::Date(int year=1900,int month=1,int day=1):_year(year),_month(month),_day(day)
{

}

Date::Date(Date& d)
{
	_year=d._year;
	_month=d._month;
	_day=d._day;
}
int Date::GetMonthDay(int year,int month)
{
	assert(year>=1900 && month>0);
	int day;
	static int MonthArray[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};
	day=MonthArray[month];
	if(month == 2 && year%400==0 || (month%4==0&&month%100!=0 ))
	{
		day=MonthArray[0];
	}
	return day;
}

bool Date::operator==(Date d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

Date Date::operator-(int day)
{
	Date tmp=*this;
	_day-=day;
	while(_day<0)
	{
		_day+=tmp.GetMonthDay(tmp._year,tmp._month);
		_month--;
		if(_month<=0)
		{
			_month=12;
			_year--;
		}
	}
	return tmp;
}


Date Date::operator+(int day)
{
	Date tmp=*this;
	_day+=day;
	while(_day>tmp.GetMonthDay(_year,_month))
	{
		_day-=tmp.GetMonthDay(_year,_month);
		_month++;
		if(_month>12)
		{
			_month=1;
			_year++;
		}
	}
	return tmp;
}

Date Date::operator=(Date d)
{
	if(!(*this==d))
	{
		_year=d._year;
		_month=d._month;
		_day=d._day;
	}
	return *this;
}

