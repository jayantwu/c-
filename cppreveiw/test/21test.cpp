
#include <cstdio>
#include <iostream>


using namespace std;
void issue_fun() {
    int n = 3;
    int arr[3] = {0};
    //arr[3] = 4;

    // arr[6] = 0; // trouble maker

    cout << hex << &n << " n=" << n << endl;
    cout << &arr[0] << " &arr[0] " << arr[0] << endl;
    cout << &arr[1] << " &arr[1] " << arr[1] << endl;
    cout << &arr[2] << " &arr[2] " << arr[2] << endl;
    cout << &arr[3] << " &arr[3] " << arr[3] << endl;
}

void call_issue()
{
    issue_fun();
    cout << "after isuue_fun" << endl;
}

int main()
{
    printf("call_issue() address: %p\n", call_issue);
    call_issue();

    cout << "Hello\rworld" << endl;

    cout << "Hello\nworld" << endl;
}