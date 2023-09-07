#include "head.h"
#include <future>
#include <thread>


template<typename T>
std::list<T> parallel_quick_sort(std::list<T> input)
{
    if (input.empty())
        return input;

    std::list<T> result;
    result.splice(result.begin(), input, input.begin()); // 将input 的第一个元素放到result list的第一个位置
    T const& pivot = *result.begin();

    auto divide_point = std::partition(input.begin(), input.end(), [&](T const& t) {return t < pivot;}); // divide_point 是一个iterator， 指向第一个大于pivot元素

    std::list<T> lower_part;
    lower_part.splice(lower_part.end(), input, input.begin(), divide_point); // divide_point 前面的元素放在lower part, 此时input 只剩下了后面的部分

    // 另起了一个线程， 这里调用了future的移动构造
    std::future<std::list<T>> new_lower(std::async(&parallel_quick_sort<T>, std::move(lower_part))); // async 返回future obj， 使用move是因为parallel_quick_sort本来是传值的

    auto new_higher(parallel_quick_sort(std::move(input)));

    result.splice(result.end(), new_higher);
    result.splice(result.begin(), new_lower.get());
    return result;
}



int main()
{
    std::list<int> l1{1,6,3,5,8,2,7,12,10};

    auto l2 = parallel_quick_sort(l1);

    for_each(l2.begin(), l2.end(), [&](int ele){ std::cout << ele; std::cout << " ";});
}




// todo: use thread pool ....