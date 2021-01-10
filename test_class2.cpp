//深拷贝、拷贝构造函数
#include <iostream>

using namespace std;

class A
{
	private:
		int* age;
	public:
		A()
		{
			age = new int;
			*age = 0;
			cout << "A()\n";
		}
		A(const A & a)
		{
			//*this = a;
			age = new int;
			*age = *(a.age);
			cout << "A(const A &)\n";
		}
		A(int n)
		{
			age = new int;
			*age = n;
			cout << "A(int n)\n";
		}
		~A()
		{
			delete age;
			cout << "~A()\n";
		}
		void show()
		{
			cout << *age << endl;
		}
		
		
};


int main()
{
	A a(2);
	A b(a);
	
	//b = a;
	a.show();
	b.show();
	//A b(a);
}
