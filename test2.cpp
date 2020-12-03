#include<iostream>

int main()
{
	using namespace std;
	
	int nights = 1001;
	int *p = new int;
	*p = 1001;
	
	cout<<"nights value = ";
	cout << nights << ": loacation " << &nights << endl;
	cout << "int value = " << *p << ": location " << p << endl;
	double *pd = new double;
	*pd = 1.1;
	
	cout << "double value = " << *pd << ": location " << pd << endl;
	cout << "sizeof p: " << sizeof(p) << endl;
	cout << "sizeof *p: " << sizeof(*p) << endl;
	cout << "sizeof pd: " << sizeof(pd) << endl;
	cout << "sizeof *pd: " << sizeof(*pd) << endl;
	delete p;
	delete pd;
	
	return 0;
	 
}


/*
nights value = 1001: loacation 0x66ff24
int value = 1001: location 0xa915d8
double value = 1.1: location 0xa915f8
sizeof p: 4
sizeof *p: 4
sizeof pd: 4
sizeof *pd: 8
*/