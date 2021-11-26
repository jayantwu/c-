#include <iostream>

using namespace std;


class Widget{
    public:
        void doWork() &
        {
            cout << "dowork &" << endl;
        }
        void doWork() &&
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
