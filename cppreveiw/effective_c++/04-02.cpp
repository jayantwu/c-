#include <iostream>
#include "04.hpp"
extern  FileSysterm& f_tfs();
extern FileSysterm tfs;
using namespace std;

class Directory
{
    public:
        Directory(int a);
};

Directory::Directory(int a)
{
    cout << a << endl;
    //tfs.numDisks();   // 无法保证在调用Directory构造函数时， tfs已经被初始化
    f_tfs().numDisks(); // 可以保证调用f_tfs时可以创建出一个fs对象
}



int main()
{
    Directory dir(5);  
}