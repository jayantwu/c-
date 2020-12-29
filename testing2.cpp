#include<iostream>
#include<string>
using namespace std;
using std::string;

class A
{
	private:
		string name;
	public:
		A(){
			cout << "use A()\n";	
		}
		A(const string &nm):name(nm){
			cout << "use A(string &nm)\n";
		}
		virtual ~A(){
			cout << "use ~A()\n";
		}
		string Name()
		{
			return name;
		}
		virtual void show()
		{
			cout << "use A::show() " << name << endl;  
		}
		
};

class B: public A
{
	private:
		int age;
	public:
		B():A(){
			cout << "use B()\n";
		}
		B(const string &nm, int n):A(nm), age(n){
			cout << "use B(const string &nm, int n)\n";
		}
	    virtual	~B(){
			cout << "use ~B()\n";
		}
		virtual void show()
		{
			cout << "use B::show() "<<Name() << "'s age is " << age << endl;
		}
		
		
		
};

class C: public A
{
	private:
		int high;
	public:
		C():A(){
			cout << "use C()\n";
		}
		C(const string &nm, int h):A(nm), high(h){
			cout << "use C(const string &nm, int h)\n";
		}
		virtual ~C()
		{
			cout << "use ~C()\n";
		}
		
	
};


int main()
{
#if 1
	B bb("wujiayang", 27);
#endif
	cout <<"*************************************************\n";
#if 1
	A a("wujiayang");
	B b("xiaoming", 24);
	A* alist[2] = {&a, &b};   //�����ึ���˻����ָ�� 
	alist[0]->show();// virtual���������� ,��������Ҳ��Ҫ����Ϊ��ģ� 
	alist[1]->show();
#endif
	cout <<"*************************************************\n";
#if 1
	A* pa[2];
	pa[0] = new A("xiaogang");
	pa[1] = new B("lili", 24);
	pa[0]->show();
	pa[1]->show();
	delete pa[0];   //ִ��deleteʱ������������� 
	delete pa[1];
#endif	
	return 0;
	
}	




/*

use A(string &nm)
use B(const string &nm, int n)
*************************************************
use A(string &nm)
use A(string &nm)
use B(const string &nm, int n)
use A::show() wujiayang
use B::show() xiaoming's age is 24
*************************************************
use A(string &nm)
use A(string &nm)
use B(const string &nm, int n)
use A::show() xiaogang
use B::show() lili's age is 24
use ~A()
use ~B()
use ~A()
use ~B()
use ~A()
use ~A()
use ~B()
use ~A()


*/