#include "tabtenn1.h"
#include<iostream>

//构造函数  使用了构造函数的初始化列表 
TableTennisPlayer::TableTennisPlayer(const string & fn, 
						const string & ln, bool ht):firstname(fn),
						lastname(ln), hasTable(ht){};

void TableTennisPlayer::Name()const
{
	std::cout << lastname << ", " <<  firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
		const string & ln, bool ht): TableTennisPlayer(fn, ln, ht)
{
	rating = r;
}
//使用了列表初始化 
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
	:TableTennisPlayer(tp), rating(r)
{
	
}
		