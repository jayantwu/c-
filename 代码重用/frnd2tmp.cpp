#include <iostream>
using namespace std;

template <typename T>
class HasFriend
{
	private:
		T item;
		static int ct;
	public:
		HasFriend(const T & i):item(i){   //每次调用这个构造函数生成对象时ct++ 
			ct++;
		}
		~HasFriend(){
			ct--;
		} 
		friend  void counts();
		friend void reports(HasFriend<T> &);
};


template <typename T>
int HasFriend<T>::ct = 0; //每个特定的具体化都有一个静态成员ct 

void counts()
{
	cout << "int count: " << HasFriend<int>::ct << "; ";
	cout << "double count: " << HasFriend<double>::ct << endl;	
}
//显式具体化 
void reports(HasFriend<int> &hf)  //某个特定具体化的友元 
{
	cout << "HasFriend<int>: " << hf.item << endl;
	
}

void reports(HasFriend<double> &hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}

int main()
{
	cout <<"No objects declared: ";
	counts();
	HasFriend<int> hfi1(10);  //调用了一次HasFriend(const T&)构造函数
	cout << "After hfi1 declared: ";
	counts();
	HasFriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
	counts();
	HasFriend<double>  hfdb(10.5);
	cout << "After hfdb declared: ";
	counts();
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);
	return 0;
	
} 



/*
HasFriend<int> hfi1(10);
发生了什么？
用int 替换了模板类中的T， 调用了 HasFriend(const T&)构造函数，初始化了item，并将ct+1 

*/