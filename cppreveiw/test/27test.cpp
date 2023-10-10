#include <iostream>
#include <vector>

using namespace std;



class Inotifier
{
    public:
        virtual void do_process()=0;
};


class ConcreteSubject
{
    public:
        void do_work()
        {
            cout << "do some work... and notify" << endl;
            for (auto notifier : notifiers) {
                notifier->do_process();
            }
        }

        void addnotifier(Inotifier* notifier) {
            notifiers.push_back(notifier);
        }

        void delnotifier(Inotifier* notifier) {

        }

    private:
        vector<Inotifier*> notifiers;

};

class Observer : public Inotifier
{
    private:
        ConcreteSubject * sub;
        bool state = false;

    public:

        Observer(ConcreteSubject* sub_ptr): sub(sub_ptr){}
        void do_main_work() {
            sub->addnotifier(this); // 相当于注册一个callback

            sub->do_work(); //执行过程中调用， 会更改 state

            if (state) {
                cout << "notify me success." << endl;
            }
            
            cout << "main work done.." << endl;
        }

        // 这个函数实际上就是作为了一个callback
       virtual void do_process() override {
           cout << "notify me...state change to ready" << endl;
           state = true;
       }
};

int main()
{
    ConcreteSubject cs;
    Observer ob{&cs};
    ob.do_main_work();
    
    return 0;
}






