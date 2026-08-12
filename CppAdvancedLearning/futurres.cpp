#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std::literals;


void producer(std::promise<int>& px)
{
    // the promise thread has started
    std::cout << "The Producer thread has started" << std::endl;

    std::this_thread::sleep_for(2s);
    std::cout << "The Producer thread has set the value" << std::endl;
    px.set_value(42);
}

void consumer(std::future<int>& py)
{
    std::cout << "The consumer thread has started" << std::endl;

    auto ans = py.get();

    std::cout << "The value gotten by the consumer thread" << ans << std::endl;
}

int main(void)
{

    std::promise<int> p;
    std::future<int> f = p.get_future();


    std::jthread thr(producer, std::ref(p));
    std::jthread thr2(consumer, std::ref(f));
}
