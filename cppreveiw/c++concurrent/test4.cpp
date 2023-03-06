#include <iostream>
#include <thread>
#include <string>
using namespace std;

class Dog {
    public:
        string name;
        int age;
        Dog(string name_, int age_): name(name_), age(age_){}
        friend ostream & operator<<(ostream & os, const Dog & dog) {
            cout << "name: " <<dog.name
            << "; age: " << dog.age << endl;
            return os;
        }
};

class DoMytask {
    public:
        void operator()(Dog & dog) {
            cout << "thread id: " << thread::id() << endl;
            cout << dog << endl;
        }

        void task1(Dog & dog) {
            for (auto i = 0; i < 5; i++) {
                cout << "thread id: " << thread::id() << endl;
                cout << "hello\n" << dog << endl;
                this_thread::sleep_for(std::chrono::milliseconds(200));
            }
        }
};


int main()
{
    Dog dog("sally", 4);
    DoMytask do_task;
    thread t1(&DoMytask::task1, &do_task, std::ref(dog));
    for (auto i = 0; i < 5; i++) {
        this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << ". ";
    }
    cout << endl;
    
    thread t2 = std::move(t1);


    t2.join();

}