#include<iostream>
#include "tv.h"

bool Tv::volup()
{
	if(volume < maxval)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
    if(volume > minval)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
        channel = 1;
	
}

void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
        channel = maxchannel;
	
}

void Tv::settings()const
{
	using std::cout;
	using std::endl;
	cout << "TV  is " << (state == off  ? "off"  : "on")  << endl;
	if  (state == on)
	{
		cout <<  "volume setting = " << volume  << endl;
		cout << "channel setting = " <<  channel << endl;
		cout << "mode = "
			<< (mode == antenna ? "antenna" : "cable") << endl;
		cout << "input  =  "
			<< (input == tv ? "tv" : "dvd") << endl;
	}
}