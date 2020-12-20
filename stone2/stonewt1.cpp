#include<iostream>
using std::cout;
#include "stonewt1.h"

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{
	
}

void Stonewt::show_stn()const
{
	cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs()const
{
	cout << pounds << " pounds\n";
}

Stonewt::operator int()const
{
	return int(pounds + 0.5);
	
}


Stonewt::operator double()const
{
	return pounds;
}


bool Stonewt::operator<(const Stonewt & s)const
{
	if (pounds < s.pounds)
		return true;
	else 
		return false;
}


std::ostream& operator<<(std::ostream & os, const Stonewt & s)
{
	os << s.pounds << " pounds\n";
	os << s.stone << " stone, " << s.pds_left << " pounds\n";
	return os;
} 

