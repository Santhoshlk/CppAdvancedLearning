#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std::literals;

void Task(std::packaged_task<int(int, int)>&& pck, int a,int b)
{

    pck(a, b); 
}

void func(std::future<int>& ftr)
{
    // first print if this is working then the print will come immediately instead of 2s later
    std::cout << "Asynchronous Programming works" << std::endl;


    std::cout << "The value :" << ftr.get() << std::endl;
}



int main(void)
{

    auto fn = [](int a, int b)
        {
            std::this_thread::sleep_for(2s);
            return a + b;
        };

    std::packaged_task <int(int, int)> pck(fn);

    // u created this 

    // first store the future
    std::future<int> ftr = pck.get_future();

    std::jthread thr(func, std::ref(ftr));
    // send this to normal fun
    std::jthread thr2(Task, std::move(pck), 5, 6);

}