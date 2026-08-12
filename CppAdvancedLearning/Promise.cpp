#include <iostream>
#include <thread>
#include <future>
#include <chrono>


void Consumer(std::shared_future<int>& ft)
{
    int a = ft.get();

    std::cout << a << std::endl;

}

void Producer(std::promise<int>& pr)
{

    pr.set_value(20);
}

int main(void)
{
    std::promise<int> p;
    std::shared_future<int> f1 = p.get_future();

    std::shared_future<int> f2 = f1;

    std::jthread thr(Consumer, std::ref(f1));
    std::jthread thr2(Consumer, std::ref(f2));
    std::jthread thr3(Producer, std::ref(p));
}
