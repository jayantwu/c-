#include "../json.hpp"
#include <fstream>

#include <iostream>

using json = nlohmann::json;
using namespace std;


namespace ns {
    // a simple struct to model a person
    struct house_t {
        std::string house_name;
        uint32_t height;
        uint32_t area;
        uint32_t value;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(house_t, house_name, height, area, value);

        void print_house()
        {
            cout << "house_name: " << house_name << "\n"
                 << "height: "     << height << "\n"
                 << "area: "       << area << "\n"
                 << "value: "      << value << "\n" << endl;
        }
    };

    struct house2_t {
        std::string house_name;
        string height;
        string area;
        uint32_t value;
        //NLOHMANN_DEFINE_TYPE_INTRUSIVE(house_t, house_name, height, area, value);

        void print_house()
        {
            cout << "house_name: " << house_name << "\n"
                 << "height: "     << height << "\n"
                 << "area: "       << area << "\n"
                 << "value: "      << value << "\n" << endl;
        }
    };

    // json 中的类型与结构体中定义的不完全一样时 需要显式转化
    void to_json(json& j, const house2_t& h) {
        j["house_name"] = h.house_name;
        j["height"] = stoi(h.height);
        j["area"] = stoi(h.area);
        j["value"] = h.value;
    }

    void from_json(const json& j, house2_t& h) {
        h.house_name = j.at("house_name");
        h.height = to_string(j.at("height"));
        h.area = to_string(j.at("area"));
        h.value = j.at("value");
    }
}

int main()
{
    ifstream f("test.json");
    json data = json::parse(f);

    cout << data.dump(4) << endl;

    ns::house_t myhouse = data.at("resource_desc").at("house_desc");

    myhouse.print_house();


    ns::house2_t myhouse2 = data.at("resource_desc").at("house_desc");

    myhouse2.print_house();



}