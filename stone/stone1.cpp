#include<iostream>
#include"stonewt1.h"

int main()
{
	using std::cout;
	Stonewt popping(9,2.8);//��ʽ���ù��캯��
	double p_wt = popping; //��ʽ����ת�� ������ת��double�� 
	cout << "convert to double => ";
	cout << " Poping: " << p_wt << " pounds.\n";
	cout << "convert to int => " ;
	cout << " Poping: " << int(popping) << " pounds.\n"; //��ʽת��
	
	Stonewt incognito = 275;  //ƥ�䵽 ���캯��Stonewt(double lbs)����275��ת��double �����ù��� 
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);     //ƥ�䵽 Stonewt(int stn, double lbs)����8��ת��double  
	
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
	 
	return 0; 
	
}