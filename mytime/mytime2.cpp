#include<iostream>
#include "mytime2.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
	
}


void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
} 

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time Time::operator+(const Time & t)const
{
	Time sum;
	sum.minutes= minutes + t.minutes;
	sum.hours  = hours + t.hours + sum.minutes / 60;
	sum.minutes = sum.minutes % 60;
	return sum;
	
}

Time Time::operator*(double m)const
{
	Time result;
	long totalminutes = hours * m * 60 + minutes * m;
	result.hours  = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}
/*
Time operator*(double m, const Time & t)  //友元函数使用了类的私有数据 
{
    Time result;
	long totalminutes = t.hours * m * 60 + t.minutes * m;
	result.hours  = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}
*/


Time operator*(double m, const Time & t)  //这个友元函数没有直接使用类的私有数据 
{
	return t * m;   //t.operator*(m) 
}
//友元函数 
std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
} 

void Time::show()const
{
	std::cout << hours << " hours, " << minutes << " minutes"; 
	
}

