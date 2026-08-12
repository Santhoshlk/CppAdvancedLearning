#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::literals;

// declare the mutex object
std::timed_mutex tmx;

void func1()
{
    std::cout << "Task 1 has locked the mutex" << std::endl;
    tmx.lock();
    std::this_thread::sleep_for(500ms);
    std::cout << "Task 1 has unlocked the mutex" << std::endl;
    tmx.unlock();
}

void func2()
{
    std::this_thread::sleep_for(100ms);
    while (!tmx.try_lock_for(100ms))
    {
        std::cout << "Task 2 cannot lock the mutex" << std::endl;
    }
    std::cout << "Task 2 has locked the mutex" << std::endl;
    std::cout << "Task 2 has unlocked the mutex" << std::endl;
    tmx.unlock();
}




int main(void)
{
    std::jthread thr(func1);
    std::jthread thr1(func2);
}
