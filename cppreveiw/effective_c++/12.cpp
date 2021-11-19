#include <iostream>
#include <string>
#include <memory>

using namespace std;

class people
{
    private:
        string name;
        int age;
    public:
        people(string n, int a):name(n), age(a){}
        people(people& p):name(p.name), age(p.age){}
        people()=default;
        virtual ~people()=default;
        people& operator=(const people & p)
        {
            name = p.name;
            age = p.age;
            return *this;
        }
        virtual void show()const
        {
            cout << "name:" << name << " age:" << age << endl;
        }


};


class student : public people
{
    private:
        int grade;
    
    public:
        student(string n, int a, int g):people(n, a), grade(g){}
        student(student& s):people(s), grade(s.grade){}
        student() = default;
        virtual ~student() = default;
        student& operator=(const student& s)
        {
            people::operator=(s);
            grade = s.grade;
            return *this;
        }
        void show()const
        {
            people::show();
            cout << "grade:" << grade << endl;
        }
};


int main()
{
    // test
    student st1("rick", 23, 5);
    st1.show();
    student st2;
    st2 = st1;
    st2.show();
    student st3(st2);
    st3.show();

    shared_ptr<people> p1(new student("tom", 25, 6));
    shared_ptr<people> p2(new people("Han", 20));

    p1->show();
    p2->show();


}