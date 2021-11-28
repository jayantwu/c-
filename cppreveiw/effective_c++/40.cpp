// MI demo
#include <iostream>
using namespace std;
class A {
    private:
        void checkout(){ cout << "I'm A 's checkout " << endl; }
};


class B {
    public:
        void checkout(){ cout << "I'm B 's checkout " << endl; }
};


class C : public A, public B {


};


//////

class iperson {
    public:
        virtual ~iperson();
        virtual string name() const = 0;
        virtual string birthday() const = 0;
};

class databaseid
{

};

class personinfo {
    public:
        explicit personinfo(databaseid pid);
        virtual ~personinfo();
        virtual const char* thename()const;
        virtual const char* thebirthday()const;
        virtual const char* valdeliopen()const;
        virtual const char* valdeliclose()const;
};

class cperson : public iperson, private personinfo {
    public:
        virtual string name() const {
            return thename();
        }
        virtual string birthday() const {
            return thebirthday();
        }

    private:
        virtual const char * valdeliopen() const {
            return "";
        }
        virtual const char* valdeliclose() const {
            return "";
        }

};


int main()
{
    C c;
    c.B::checkout();   //这里的checkout 函数必须指明， 即使 A::checkout 是一个private的
}