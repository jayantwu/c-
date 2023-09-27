// g++ -o test 22test.cpp -I/usr/include/python3.6m -lpython3.6m

#include <Python.h>
#include <string>

int main()
{
    Py_Initialize();
//     std::string p_code = R"(
// print('hello world');
// for i in range(2):
//     print('hello'))";
    std::string p_code = 
    "print('hello world')\n"
    "for i in range(2):\n"
    "    print('hello')";

    PyRun_SimpleString(p_code.c_str());
    Py_Finalize();

    return 0;

}