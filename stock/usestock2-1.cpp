#include<iostream>
#include "stock20.h"

const int STKS = 4;

int main()
{
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 6.5),
		Stock("Fleep Enterprises", 60, 6.5) 
	};
	
	std::cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
	{
		stocks[st].show();
	} 
	
	//声名一个指针指向对象数组的第一个元素
	const Stock *top = &stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);  //top指针记录每次比较大的那个对象的地址 
	std::cout << "\nMost valuable holding:\n";
	top->show();
	return 0; 
}