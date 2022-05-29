#include "json.hpp"
#include <iostream>
#include <vector>
#include <functional>

using namespace std;
using json = nlohmann::json;

//using f = function<void()>;
typedef void(*f)();
void myfun()
{
    cout << "aaa" << endl;
}

int main()
{
    json j;
    json j0;
    j["a"] = 1;
    j["b"] = 2;
    cout << j.dump(4) << endl;

    j["lsp_lbl1"] = vector<uint32_t>{1111, 2222, 3333, 4444};

    cout << j.dump(4) << endl;

    //auto v = j["lsp_lbl"].get<vector<uint32_t>>

    j["lsp_lbl2"] = { {"tnl_idx", 123}, {"ref_cnt", 5} };

    cout << j.dump(4) << endl;

    cout << j["lsp_lbl2"]["ref_cnt"].get<uint32_t>() << endl;


    j["lsp_lbl2"]["ref_cnt"] = j["lsp_lbl2"]["ref_cnt"].get<uint32_t>() - 1;
    cout << j["lsp_lbl2"]["ref_cnt"] << endl;


    if (j.contains("lsp_lbl2") != false)
    {
        cout << "hahah" << endl;
    }



    int a = 8;

    int b = 8 | 1 << 2;
    cout << b << endl;

    if (j["a"] > 0)
        cout << "bigger" << endl;


    j.clear();
    cout << j.dump(4) << endl;

    j0["a"] = {{"lsp", 1000}, {"lbl", 10000}};
    //j0.push_back(myfun);
    //j0.push_back("lbl");
    //f fun = j0["oid"]["fun"];
    cout << j0.dump(4) << endl;


}