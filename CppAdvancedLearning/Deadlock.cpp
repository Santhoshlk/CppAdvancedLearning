#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::literals;
std::mutex mtx1;
std::mutex mtx2;

// this is an example of mutual deadlock
// to get of stuck use ^c

void func1()
{
    std::cout << "Thread 1 has tried to lock the mutex 1" << std::endl;
    std::lock_guard lck(mtx1);
    std::cout << "Thread 1 has locked mutex 1" << std::endl;

    std::this_thread::sleep_for(50ms);
    std::cout << "Thread 1 has tried to lock the mutex 2" << std::endl;
    std::lock_guard lck2(mtx2);
    std::cout << "Thread 1 has locked mutex 2" << std::endl;
}

void func2()
{
    std::cout << "Thread 2 has tried to lock the mutex2" << std::endl;
    std::lock_guard lck(mtx2);
    std::cout << "Thread 2 has locked mutex 2" << std::endl;

    std::this_thread::sleep_for(50ms);
    std::cout << "Thread 2 has tried to lock the mutex 1" << std::endl;
    std::lock_guard lck2(mtx1);
    std::cout << "Thread 2 has locked mutex 1" << std::endl;
}

int main(void)
{
    std::jthread thr(func1);
    std::jthread thr2(func2);
}
