#include "tabtenn0.h"
#include<iostream>

//构造函数  使用了构造函数的初始化列表 
TableTennisPlayer::TableTennisPlayer(const string & fn, 
						const string & ln, bool ht):firstname(fn),
						lastname(ln), hasTable(ht){};

void TableTennisPlayer::Name()const
{
	std::cout << lastname << ", " <<  firstname;
}
/*
TableTennisPlayer::TableTennisPlayer(const string & fn, 
						const string & ln, bool ht)
{
	firstname  = fn;
	lastname = ln;
	hasTable = ht;
}

*/