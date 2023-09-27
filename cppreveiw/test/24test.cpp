#include <iostream>
#include <mutex>
#include <memory>

using namespace std;
int main()
{
    weak_ptr<int> w_ptr;
    {
        shared_ptr<int> s_ptr = make_shared<int>(5);

        w_ptr = s_ptr;
    }
    shared_ptr<int> s_ptr2 = w_ptr.lock();
    if (s_ptr2 == nullptr) {
        cout << "s_ptr2 is nullptr" << endl;
    }

    //cout << s_ptr.use_count() << endl;

    return 0;
}