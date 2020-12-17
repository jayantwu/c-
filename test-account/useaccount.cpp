#include "account.h"


int main()
{
	
	MyAccount myaccount("JiayantWu", "66668888", 1234);
	myaccount.show();
	
	myaccount.withdraw(20);
	myaccount.show();
	
	myaccount.deposit(150);
	myaccount.show();
}
