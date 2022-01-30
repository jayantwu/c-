#include <iostream>
#include <functional>
#include <vector>
#include <memory>
using namespace std;

//-----------------------------------------------------------------------------
// define an interface we can call regardless of the return type

struct task_itf
{
    virtual ~task_itf() = default;
    virtual void operator()() = 0;
protected:
    task_itf() = default;
};

//-----------------------------------------------------------------------------
// define a task for functions with a return type

template<typename retval_t>
struct task :
    public task_itf
{
public:
    task(std::function<retval_t()> fn) :
        m_fn{ fn }
    {
    };

    retval_t& get() 
    {
        return m_result;
    }

    void operator()() override
    {
        m_result = m_fn(); // call function
    }

private:
    std::function<retval_t()> m_fn;
    retval_t m_result;
};

//-----------------------------------------------------------------------------
// specialize a task for functions without return type

template<>
struct task<void> :
    public task_itf
{
    task(std::function<void()> fn) :
        m_fn{ fn }
    {
    };

    // for demo purpose, in production code I would get do nothing and return a void
    const char* get() 
    {
        static const char* retval{ "<void>" };
        return retval;
    }

    void operator()() override
    {
        m_fn();
    }

private:
    std::function<void()> m_fn;
};

//-----------------------------------------------------------------------------

void f1() {};
int f2() { return 42; };
char f3() { return 'c'; };

int main()
{
    task<void> task1{ f1 };
    task<int> task2{ f2 };
    task<char> task3{ f3 };

    //std::vector<std::reference_wrapper<task_itf>> tasks{ task1,task2,task3 };
    std::vector<shared_ptr<task_itf>> tasks{ make_shared<task<void>>(f1),
                                             make_shared<task<int>>(f2),
                                             make_shared<task<char>> (f3) 
                                            };
    for (const auto& task : tasks)
    {
        //task(); // call the wrapped functions
        (*task)();
    }
    //cout << "result of f1 = " << tasks[0]->get() << endl;

    //std::cout << "result of f1 = " << task1.get() << "\n";
    //std::cout << "result of f2 = " << task2.get() << "\n";
    //std::cout << "result of f3 = " << task3.get() << "\n";

    return 0;
}