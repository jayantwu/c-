#include "redis.h"
#include <string>
#include <unistd.h>
int main()
{
    Redis *r = new Redis();
    if(!r->connect("127.0.0.1", 7777))
    {
        printf("connect error!\n");
        return 0;
    }
    r->set("name", "Andy");
    r->set("age", "22");
    r->set("Andy", "info");
    printf("Get the name is %s\n", r->get("name").c_str());
    if (r->get("name") == "Andy")
    {   std::string s = r->get("Andy");
        printf("get Andy's info : %s\n", s.c_str());
    }

    sleep(10);

    r->del("name");
    r->del("Andy");

    delete r;
    return 0;
}
