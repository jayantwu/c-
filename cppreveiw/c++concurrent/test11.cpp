#include <mutex>
#include <thread>
#include <iostream>
 
std::once_flag flag, flag2;
uint32_t g_num=1;
uint32_t g_num2=2;

void init_resource(uint32_t n)
{
    std::cout << "init resource" << std::endl;
    g_num += n;
}


void access_resource()
{
    std::call_once(flag, init_resource, 3);
    std::cout << "access resource" << std::endl;

    std::cout << g_num << std::endl;
}

class X {
    public:
        void init_resource(uint32_t n)   //static void init_resource(uint32_t n)
        {
            std::cout << "init resource2" << std::endl;
            g_num2 += n;
        } 
};

class Y {
    public:
        void access_resource()
        {
            /*  if no Y::
            test11.cpp:37:36: error: ISO C++ forbids taking the address of an unqualified or 
            parenthesized non-static member function to form a pointer to member function.  
            Say ‘&Y::init_internal’ [-fpermissive]
            */
            std::call_once(flag2, &Y::init_internal, this, 3);  

            // std::call_once(flag2, &X::init_resource, 3); // if init_resource is a static mbr function, no need  "this"
            std::cout << "access resource2" << std::endl;

            std::cout << g_num2 << std::endl;
        }

        void init_internal(uint32_t n)
        {
            X x;
            x.init_resource(n);
        }

};

int main()
{

    std::thread t1{access_resource};
    std::thread t2{access_resource};
    std::thread t3{access_resource};

    Y y;
    std::thread t4{&Y::access_resource, &y};
    std::thread t5{&Y::access_resource, &y};
    std::thread t6{&Y::access_resource, &y};

 
    t1.join();
    t2.join();
    t3.join();

    t4.join();
    t5.join();
    t6.join();

}