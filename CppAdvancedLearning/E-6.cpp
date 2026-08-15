#include <iostream>
#include <thread>
#include <future>
#include <chrono>

int main(void)
{
    std::promise<int> promise;

    std::future<int> ftr = promise.get_future();

    auto Consumer = [&]()
        {
            std::cout << "Asynchronous Programming works" << std::endl;
            std::cout << "The value:" << ftr.get() << std::endl;
        };

    auto Producer = [&]( int a, int b)
        {

            std::this_thread::sleep_for(std::chrono::seconds(2));
            promise.set_value(a + b);
        };

    // call the threads
    std::jthread thr(Consumer);
    std::jthread thr2(Producer,6,7);
}