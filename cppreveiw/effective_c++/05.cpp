#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class NamedObject
{
    public:
        NamedObject(string &name, const T& value):nameValue(name), objectValue(value){}
        void show()
        {
            cout << nameValue << setw(4) << setfill(' ') << objectValue << endl;
        }

    private:
        string  nameValue;   // string&  nameValue;
         T objectValue;  // const T objectValue;

};




int main()
{
    string newDog("perseph");
    string oldDog("Satch");
    NamedObject<int> p(newDog, 2);
    NamedObject<int> s(oldDog, 23);
    p.show();
    
    p = s;  // error if nameValue is reference or objectValue is const
    p.show();


    return 0;

}