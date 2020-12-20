#include<iostream>
#include"stonewt1.h"

int main()
{
	using std::cout;
	Stonewt popping(9,2.8);//隐式调用构造函数
	double p_wt = popping; //隐式类型转换 ，将类转成double型 
	cout << "convert to double => ";
	cout << " Poping: " << p_wt << " pounds.\n";
	cout << "convert to int => " ;
	cout << " Poping: " << int(popping) << " pounds.\n"; //显式转换
	
	Stonewt incognito = 275;  //匹配到 构造函数Stonewt(double lbs)，将275先转成double 并调用构造 
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);     //匹配到 Stonewt(int stn, double lbs)，将8先转成double  
	
	cout << "the celebrity weighed ";
	incognito.show_stn();
	cout << "the detective wighed ";
	wolfe.show_stn();
	cout << "the president wighed ";
	taft.show_lbs();
	incognito = 276.8;
	taft = 325;
	cout << "afte dinner, the celebrity weighed ";
	incognito.show_lbs();
	cout << "afte dinner, the president weighed ";
	taft.show_lbs();
	
	//test6
	Stonewt st[6] = {
		Stonewt(2.1), Stonewt(2.2), Stonewt(1, 2.3), taft   //显式的使用构造函数初始化数组成员 
	};
	
	if (st[0] < st[1])
		cout << "yes ,st[0] < st[1]\n";
	else
		cout << "no, st[0] >= st[1]\n";
 	
 	for (int i = 0; i < 6; i++)
 		cout << "st[" << i << "]: \n"<< st[i]<< "\n";
	return 0; 
	
}