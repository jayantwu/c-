#include<iostream>
#include "stock00.h"

void Stock::acquire(const std::string &co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		
		std::cout<< "Number of shares cant be negative;" 
		<< company << " shares set to 0. \n";
		shares = 0;
	}
	
	else
		shares = n;
	share_val = pr;
	set_tot();
	
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased cant be negative. "
		<< "Transaction is aborted.\n";
		
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares sold cant be negative. "
		<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "Number of shares sell more than you have. "
		<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}



void Stock::update(double price)
{
	share_val = price;
	set_tot();
} 


void Stock::show()
{
	std::cout << "company: " << company
	<< " shares: " << shares << '\n'
	<< " share price: $" << share_val 
	<< "total worth: $" << total_val << std::endl; 
}


