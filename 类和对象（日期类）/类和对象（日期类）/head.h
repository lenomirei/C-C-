#include<iostream>
#include<assert.h>
using namespace std;

class Date
{

	
public:

	friend ostream& operator <<(ostream &os,const Date& d);
	friend istream& operator >>(istream &is,Date& d);



	void display();
	Date(int year=1900,int month=1,int day=1)
	{
		_year=year;
		_month=month;
		_day=day;
	}
	
	Date(Date &d)
	{
		_year=d._year;
		_month=d._month;
		_day=d._day;
	}
	bool operator==(Date d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	bool operator >(Date d);
	bool operator <(Date d);
	bool operator >=(Date d);
	bool operator <=(Date d);
	Date operator +(int day);
	Date operator =(Date d);
	Date operator -(int day);
	int operator -(Date d);
	Date operator -=(int day);
	Date operator +=(int day);
	Date operator ++();
	Date operator ++(int);
	Date operator --();
	Date operator --(int);
private:
	int GetMonthDay(int year,int month);
	int _year;
	int _month;
	int _day;
};

bool Date::operator >(Date d)
{
	if(_year>d._year)
	{
		return true;
	}
	else if(_year==d._year)
	{
		if(_month > d._month)
		{
			return true;
		}
		else if(_month==d._month)
		{
			if(_day>d._day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Date::operator <(Date d)
{
	return !(*this>d || *this==d);
}

bool Date::operator <=(Date d)
{
	return *this<d || *this==d;
}

bool Date::operator >=(Date d)
{
	return *this>d || *this==d;
}

void Date::display()
{
	cout<<_year<<'-'<<_month<<'-'<<_day<<endl;
}

int Date::GetMonthDay(int year,int month)
{
	assert(year>=1900 && month>0);
	int day;
	static int MonthArray[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};
	day=MonthArray[month];
	if(month == 2 && (year%400==0 || (month%4==0&&month%100!=0 )))
	{
		day=MonthArray[0];
	}
	return day;
}

Date Date::operator-(int day)
{
	Date tmp=*this;
	if(day>0)
	{
		tmp._day-=day;
		while(tmp._day<=0)
		{
			tmp._day+=tmp.GetMonthDay(tmp._year,tmp._month);
			tmp._month--;
			if(tmp._month<=0)
			{
				tmp._month=12;
				tmp._year--;
			}
		}
	}
	else
	{
		tmp=*this+day;
	}
	return tmp;
}
Date Date::operator -=(int day)
{
	*this=*this-day;
	return *this;

}


Date Date::operator+(int day)
{
	Date tmp=*this;
	if(day>=0)
	{
		tmp._day+=day;
		while(tmp._day>tmp.GetMonthDay(tmp._year,tmp._month))
		{
			tmp._day-=tmp.GetMonthDay(_year,_month);
			tmp._month++;
			if(tmp._month>12)
			{
				tmp._month=1;
				tmp._year++;
			}
		}
	}
	else
	{
		tmp=*this-day;
	}
	return tmp;
}

Date Date::operator +=(int day)
{
	*this=*this+day;
	return *this;
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

int Date::operator -(Date d)
{

	int result=0;

	if(_year==d._year)
	{
		for(int i=d._month;i<_month;i++)
		{
			result+=d.GetMonthDay(d._year,i);
		}
	}

	else
	{
		for(int i=0;i<d._month-1;i++)
		{
			result+=d.GetMonthDay(d._year,i);
		}
		for(int i=_month;i<12;i++)
		{
			result+=d.GetMonthDay(d._year,i);
		}
		for(int i=_year+1;i<d._year;i++)
		{
			result+=365;
		}
	}
	if(_month==d._month)
	{
		result+=(_day-d._day);
	}
	else
	{
		result+=d._day;
		result=result+this->GetMonthDay(_year,_month-1)-_day;
	}
	if(*this>d)
	{
		return result;
	}
	else
	{
		return -result;
	}
}
	


Date Date::operator --()
{
	*this-=1;
	return *this;
}

Date Date::operator--(int)//back
{
	Date tmp=*this;
	*this-=1;
	return tmp;
}


Date Date::operator ++()
{
	*this+=1;
	return *this;
}
Date Date::operator ++(int)
{
	Date tmp=*this;
	*this+=1;
	return tmp;
}


ostream& operator <<(ostream &os,const Date& d)
{
	os<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
	return os;
}
istream& operator >>(istream &is,Date& d)
{
	is>>d._year>>d._month>>d._day;
	return is;
}