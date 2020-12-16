#include<iostream>
#include "stock10.h"
int main()
{
	using std::cout;
	cout << "using constructor to create new objects\n";
	Stock stock1("Nanosmart", 12, 20.0);  //隐式调用构造函数 ，不创建临时对象 
	stock1.show();
	Stock stock2 =  Stock("Boffo Objects", 2, 2.0);  //显式调用构造函数， 这种方式有两种方式实现：是否创建一个临时对象 
	stock2.show();
	
	cout << "Assigning stock1 to stock2:\n";
	stock2 = stock1;  
	cout << "Listing stock1 and stock2:\n";
	stock1.show();
	stock2.show();
	
	cout << "using a  constructor to reset an object\n";
	stock1 = Stock("Nifty Foods", 10, 50.0); //赋值 ，会创建一个临时对象 
	cout << "revised stock1:\n";
	stock1.show();
	cout << "Done!\n"; 
	

	return 0;
}


/*output

using constructor to create new objects
Constructor using Nanosmart called
company: Nanosmart shares: 12
 share price: $20.000
total worth: $240.00
Constructor using Boffo Objects called
company: Boffo Objects shares: 2
 share price: $2.000
total worth: $4.00
Assigning stock1 to stock2:
Listing stock1 and stock2:
company: Nanosmart shares: 12
 share price: $20.000
total worth: $240.00
company: Nanosmart shares: 12
 share price: $20.000
total worth: $240.00
using a  constructor to reset an object
Constructor using Nifty Foods called
Bye, Nifty Foods!
revised stock1:
company: Nifty Foods shares: 10
 share price: $50.000
total worth: $500.00
Done!
Bye, Nanosmart!
Bye, Nifty Foods!


*/