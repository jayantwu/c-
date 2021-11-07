// set::begin/end
#include <iostream>
#include <set>
#include <vector>

int main ()
{
  int myints[] = {75,23,65,42,13};
  std::set<int> myset (myints,myints+5);

  std::cout << "myset contains:";
  for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  myset.clear();

  // set some initial values:
  for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

  for (int i=0; i<10; ++i)
  {
    std::cout << i;
    if (myset.count(i)!=0)
      std::cout << " is an element of myset.\n";
    else
      std::cout << " is not an element of myset.\n";
  }

  myset.clear();


  std::set<int>::iterator it;

  // insert some values:
  for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

  
  for (it=myset.begin(); it!=myset.end(); ++it) 
    std::cout << *it << " " << std::endl;
  it = myset.begin();
  ++it;                                         // "it" points now to 20

  myset.erase (it);   // 通过iterator删除一个元素

  myset.erase (40);

  it = myset.find (60);
  myset.erase (it, myset.end());   // 指定一个范围

  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  //11.7 update
  std::vector<int> v{1, 4, 6, 2, 7};

  std::set<int>  s{v.begin(), v.end()};

  std::cout << "s size is " <<  s.size() << std::endl;

  for (std::set<int>::iterator it = s.begin() ; it != s.end(); it++)
    std::cout << *it << std::endl;  // 1 2 4 6 7

  for (auto i : s)
    std::cout << i << std::endl;



  return 0;
}



/*
myset contains: 13 23 42 65 75
0 is not an element of myset.
1 is not an element of myset.
2 is not an element of myset.
3 is an element of myset.
4 is not an element of myset.
5 is not an element of myset.
6 is an element of myset.
7 is not an element of myset.
8 is not an element of myset.
9 is an element of myset.
10 
20 
30 
40 
50 
60 
70 
80 
90 
myset contains: 10 30 50
*/
