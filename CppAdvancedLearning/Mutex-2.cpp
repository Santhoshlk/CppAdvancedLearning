#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::literals;

static int a = 0;

std::mutex thread_guard;

void func1()
{
    std::cout << "Thread A has started the execution" << std::endl;
    //critical section
    while (!thread_guard.try_lock())
    {
        // let this thread sleep 
        std::cout << "Thread B has locked " << std::endl;
        std::this_thread::sleep_for(100ms);
    }
    std::cout << "Thread A has locked the mutex" << std::endl;
    for (int i = 0; i < 100000; i++)
    {
        a++;
    }
    //now unlock it
    thread_guard.unlock();
}

void func2()
{
    // for giving thread a an advantage 

    std::this_thread::sleep_for(200ms);
    std::cout << "Thread B has started the execution" << std::endl;
    //critical section
    while (!thread_guard.try_lock())
    {
        // let this thread sleep 
        std::cout << "Thread A has locked " << std::endl;
        std::this_thread::sleep_for(100ms);
    }
    std::cout << "Thread B has locked the mutex" << std::endl;
    for (int i = 0; i < 100000; i++)
    {
        a++;
    }
    //now unlock it
    thread_guard.unlock();
}


int main(void)
{
    std::thread thr(func1);
    std::thread thr2(func2);

    thr.join();
    thr2.join();
    std::cout << "The value of a :" << a << std::endl;
}
