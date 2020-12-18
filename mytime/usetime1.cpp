#include<iostream>
#include "mytime1.h"

int main()
{
	using std::cout;
	using std::endl;
	Time planning;  //使用默认构造函数初始化
	Time coding(2, 40);  //隐式调用构造函数
	Time fixing(5, 55);
	Time total;
	
	
	cout << "planning time = ";
	planning.show();
	cout << endl;
	
	cout << "coding time = ";
	coding.show();
	cout << endl;
	
	cout << "fixing time = ";
	fixing.show();
	cout << endl;
	
	total = coding + fixing;
	
	cout << "coding + fixing = ";
	total.show();
	cout << endl;
	
	Time morefixing(3, 28);
	
	cout << "more fixing time = ";
	morefixing.show();
	cout << endl;
	
	total = morefixing.operator+(total);
	cout << "morefixing.operator+(total) = ";
	total.show();
	cout << endl;
	
	Time adjusted = total * 1.5;
	cout << "adjusted work time total * 1.5= ";
	adjusted.show();
	cout << endl;
	
	Time adjusted2 = 2.0 * total;
	cout << "adjusted2 work time 2.0 * total = ";
	adjusted2.show();
	cout << endl;
	
	return 0; 
	 
	
}

/*
planning time = 0 hours, 0 minutes
coding time = 2 hours, 40 minutes
fixing time = 5 hours, 55 minutes
coding + fixing = 8 hours, 35 minutes
more fixing time = 3 hours, 28 minutes
morefixing.operator+(total) = 12 hours, 3 minutes
adjusted work time total * 1.5= 18 hours, 4 minutes
adjusted2 work time 2.0 * total = 24 hours, 6 minutes


*/