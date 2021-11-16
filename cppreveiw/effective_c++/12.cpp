#include <iostream>
#include <string>

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
    

}