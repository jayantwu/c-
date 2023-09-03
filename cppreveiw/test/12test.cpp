#include "json.hpp"
#include <iostream>
#include <vector>
#include <functional>
#include <cassert>

using namespace std;
using json = nlohmann::json;

//using f = function<void()>;
typedef void(*f)();
void myfun()
{
    cout << "aaa" << endl;
}

namespace ns {
    // a simple struct to model a person
    struct person {
        std::string name;
        std::string address;
        int age;
        //NLOHMANN_DEFINE_TYPE_INTRUSIVE(person, name, address, age)
    };

    void to_json(json& j, const person& p) {
        j = json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
    }

    void from_json(const json& j, person& p) {
        j.at("name").get_to(p.name);
        j.at("address").get_to(p.address);
        j.at("age").get_to(p.age);
    }
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


    // create a person
    ns::person p {"Ned Flanders", "744 Evergreen Terrace", 60};

    // conversion: person -> json
    json js = p;

    std::cout << js << std::endl;
    // {"address":"744 Evergreen Terrace","age":60,"name":"Ned Flanders"}

    // conversion: json -> person
    auto p2 = js.get<ns::person>();

    cout << p2.name << endl;

    // that's it
    //assert(p == p2);


}