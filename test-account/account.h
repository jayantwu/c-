#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include<string>

class MyAccount
{
private:
	std::string name;
	std::string account;
	int total_money;
public:
	MyAccount();
	MyAccount(const std::string nm, const std::string acc, int to_mo);
	void show() const;
	void deposit(int m);
	void withdraw(int m);	
};

#endif