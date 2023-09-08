#include "head.h"
#include <future>
#include <thread>
#include <functional>


std::function<void(void)> state;
class test_state {
    public:
    void step1()
    {
        std::cout << "process step 1" << std::endl;
        state = std::bind(&test_state::step2, this);
    }
    void step2()
    {
        std::cout << "process step 2" << std::endl;
        state = std::bind(&test_state::step3, this);
    }
    void step3()
    {
        std::cout << "process step 3" << std::endl;
        std::cout << "process end" << std::endl;
    }

};


int main()
{
    test_state t;
    state = std::bind(&test_state::step1, &t);
    int i = 0;
    for (;;)
    {
        state();
        i++;
        if (i > 2)
            break;
    }
    return 0;
}




// todo: use thread pool ....