#include <iostream>

using namespace std;


class Widget{
    public:
        void doWork() &   //对象是一个lval时调用
        {
            cout << "dowork &" << endl;
        }
        void doWork() &&    //对象是一个rval时调用
        {
            cout << "dowork &&" << endl;
        }
};


Widget makeWidget()
{
    return Widget();
}

int main()
{
    Widget w;
    w.doWork();

    makeWidget().doWork();


}
