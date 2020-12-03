#include<iostream>
int main()
{
	using namespace std;
	char ch = 'M';
	char name[20];
	int num;
	int i = ch;
	cout << "the ascii code for "<< ch << " is " << i << endl;
	cout<<"please input a num:"<<endl;
	(cin>>num).get();  //回车会留在cin的输入队列中，所以这里需要再get()读取输入队列的换行符 
	cout<<"the num you input is "<<num<<endl;
	cout<<"input your name: ";
	cin.getline(name, 20);
	cout<<"your name is "<<name<<endl;
	//cout<<R"(wu jiayang uses "\n" instead of endl.)"<<'\n';
	return 0;
}
