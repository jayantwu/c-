#include <iostream>
#include <functional>
#include <vector>
#include <thread>
#include <stdio.h>


using namespace std;


class B {
    public:

        static B* get_instance() {
            if (m_instance == nullptr) {
                m_instance = new B();
                cout << "create B instance" << endl;
            }
            return m_instance;
        }

        void register_cb(function<void(void)> f) {
            cb = f;
        }

        void do_process() {
            if (cb != nullptr)
                cb();
            else {
                cout << "cb is not point to a fun" << endl;
            }
        }
    private:
        function<void(void)> cb;
        static B * m_instance;
};

B* B::m_instance = nullptr;

struct data {
    int d = 10;
};

class A {
    public:
        void fun();
        void print() { cout << "hello" << endl;}
    private:
        data a;
};

void A::fun() {
    cout << "enter A::fun()" << endl;
    static function<void(void)> f = [&](void) {
        cout << "a = " <<  a.d << endl;
        this->print();
        this->a;
    };

    this_thread::sleep_for(chrono::milliseconds(500));
    B* b_ptr = B::get_instance();
    b_ptr->register_cb(f);

}



class Base {
    public:
        int a;
};

class derive : public Base {
    public:
        int b;
};






int main()
{
    A a;
    //a.fun();
    thread t(&A::fun, &a);
    if (B::get_instance() == nullptr) {
        cout << "B::m_instamce is nullptr" << endl;
    }

    this_thread::sleep_for(chrono::milliseconds(600));
    B::get_instance()->do_process();
    t.join();
    vector<function<void(void)>> v_funs;
    {
        function<void(void)> f = [] {
            cout << "world" << endl;
        };
        v_funs.push_back(f);
    }

    v_funs[0]();

    Base* a_ptr = new derive();

    //a_ptr->b = 0;

    cout << "size.." << v_funs.size() << endl;
    for (auto & fun : v_funs) {
        cout << "fun..." << endl;
        fun();
    }


    return 0;
}