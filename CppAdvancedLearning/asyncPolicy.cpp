#include <iostream>
#include <thread>
#include <string>
#include <future>

int Task(int a,int b)
{
    std::cout << "The task  thread ID :" << std::this_thread::get_id() << std::endl;
    return a + b;
}

void func(const std::string& str)
{
    if (str == "async")
    {
        auto ftr = std::async(std::launch::async, Task, 5, 6);
        std::cout << "The func thread ID :" << std::this_thread::get_id() << std::endl;;
        std::cout << "The value :" << ftr.get() << std::endl;
    }
    else 
    {
        auto ftr = std::async(std::launch::deferred, Task, 5, 6);
        std::cout << "The func thread ID :" << std::this_thread::get_id() << std::endl;;
        std::cout << "called after get()" << std::endl;
        std::cout<<ftr.get() << std::endl;
    }
}



int main(void)
{
    std::string a("async");
    std::string b = "deferred";
    std::jthread thr(func, std::cref(a));

    std::jthread thr2(func, std::cref(b));
}