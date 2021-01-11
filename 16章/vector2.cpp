#include <iostream>
#include<string>
#include<vector>
using namespace std;
struct Review{
	string title;
	int  rating;
};

bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
	vector<Review> books;   //声名了一个vector数组 类型为Review
	Review temp;
	while (FillReview(temp))
	{
		books.push_back(temp);
	} 
	int num = books.size();
	if (num > 0)
	{
		cout << "Thank youm,  you entered the following:\n"
		<< "Rating\tBook\n";
		for (int i = 0; i  < num; i++)
			ShowReview(books[i]);
		cout <<  "Reprising:\n"
		<< "Rating\tBook\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
		
		vector<Review> oldlist(books);     //拷贝构造函数 
		if (num > 3)
		{
			//remove 2 items
			books.erase(books.begin() + 1, books.begin()+3);
			cout <<  "after  erasure:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
			//插入一元素 
			books.insert(books.begin(), oldlist.begin()+1, oldlist.begin()+2);
			//after insert
			cout <<  "After  intering:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		} 
		books.swap(oldlist);
		cout << "swaping oldlist with books:\n";
		for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		
	}
	else
		cout << "Nothing enntered, nothing gained.\n";
}

bool FillReview(Review & rr)
{
	cout << "Enter book title (quit to quit): ";
	getline(cin, rr.title);
	if (rr.title== "quit")
		return false;
	cout << "Enter book rating: ";
	cin >> rr.rating;
	if (!cin)
		return false;
	while (cin.get()!= '\n')
		continue;
	return true;
}


void ShowReview(const Review & rr)
{
	cout << rr.rating << "\t" << rr.title << endl;
}