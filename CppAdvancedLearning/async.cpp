#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;


int main(void)
{
    auto fn = [](int a, int b)
        {
            std::this_thread::sleep_for(10s);
            return a + b;
        };

    auto ftr = std::async(std::launch::async,fn,5,6);

    auto task = [&]()
        {
            // first print if this is working then the print will come immediately instead of 2s later
            std::cout << "Asynchronous Programming works" << std::endl;

            while (ftr.wait_for(1s) != std::future_status::ready)
            {
                std::cout << "Waiting for the value" << std::endl;
            }

            std::cout << "The value :" << ftr.get() << std::endl;
        };

    std::jthread thr(task);

}