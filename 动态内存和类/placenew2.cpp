#include<iostream>
#include<string>
#include<new>

using namespace std;
const int BUF = 512;
class JustTesting
{
	private:
		string words;
		int number;
	public:
		JustTesting(const string & s = "Just Testing", int n = 0)  //参数有默认值  因而可以不需要默认构造函数 
		{
			words = s; 
			number = n;
			cout << words << " constructed\n";
		}
		
		~JustTesting()
		{
			cout << words << " destroyed\n";
		}
		void Show()const
		{
			cout << words << ", " << number << endl;
		}
		
} ;

int main()
{
	char *buffer = new char[BUF];  //常规的new运算符 
	
	JustTesting *pc1, *pc2;
	
	pc1 = new (buffer) JustTesting;  //定位new运算符  
	pc2 = new JustTesting("Heap1", 20);
	
	cout << "Memory block addresses:\n" << "buffer: "
	<< (void*)buffer << "  heap:" << pc2 << endl;
	
	cout << "Memory contents:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 <<": ";
	pc2->Show();
	
	JustTesting *pc3, *pc4;
	pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Better idea", 6);   //定位new运算符  加了偏移之后 
	pc4 = new JustTesting("Heap2", 10);
	
	cout << "Memory contents:\n";
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 <<": ";
	pc4->Show();
	
	delete pc2;
	delete pc4;
	pc3->~JustTesting(); //销毁pc3指向的对象 
	pc1->~JustTesting();
	delete [] buffer;
	cout << "Done!\n";
	return 0;
}