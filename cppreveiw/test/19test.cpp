#include <iostream>
#include <functional>
#include <string>

using namespace std;


class PrintN {
    public:
        PrintN() {
            cout << "i'm constructor.." << endl;
        }

        void operator()(int a, int b) {
            cout << "print: " << a + b << endl;
        }

        void print_str(string s) {
            cout << s << endl;
        }
};



int main() 
{
    //function<void(int, int)> printfunctor = PrintN();
    auto printfunctor = PrintN();

    printfunctor(6, 7);

    printfunctor.print_str("hello world");

    PrintN().print_str("hello all");
    PrintN()(4, 5);
}