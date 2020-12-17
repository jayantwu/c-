#include "account.h"
#include <iostream>
MyAccount::MyAccount()
{
	name = "no name";
	account = "defaut accout";
	total_money = 0;
}

MyAccount::MyAccount(const std::string nm, const std::string acc, int to_mo)
{
	name = nm;
	account = acc;
	total_money = to_mo;
}

void MyAccount::show()const
{
	std::cout << name << "'s accout is " << account  << " , total  money is："
	     <<  total_money << ".\n"; 
}

void MyAccount::deposit(int m)
{
	total_money += m;
}

void MyAccount::withdraw(int m)
{
	if (total_money - m < 0)
		std::cout << "no enough  money to withdraw!\n";
	else
		total_money  -= m;
}