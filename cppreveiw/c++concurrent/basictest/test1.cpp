#include "my.h"

using namespace std;


class functor
{
    public:
        void operator()(int a, int b) {
            cout << fmt::format("{} + {} = {}", a, b, a+b) << endl;
            int tmo = 1000;
            for (; tmo >= 0; tmo-=100) {
                this_thread::sleep_for(1000ms);
                cout << fmt::format("sleep {}s", (1000-tmo)/100) << endl;
            }
        }
};


int main()
{
    thread t1([](){ 
        cout << "hello world\n";
        this_thread::sleep_for(5000ms);
        });

    functor f1;
    //f1(1, 2);
    //thread t2(f1, 1, 2);
    thread t3([&](){ f1(1, 2); });
    t1.join();
    //t2.join();
    t3.join();

    return 0;
}