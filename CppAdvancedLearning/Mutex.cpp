#include <iostream>
#include <thread>
#include <string>
#include <mutex>

std::mutex thread_guard;

void Print(const std::string& str)
{
    //critical section 
    //when all will use std::cout
    thread_guard.lock();
    for (int i = 0; i < 4; i++)
    {
        std::cout << str[0] << str[1] << str[2] << std::endl;
    }
    thread_guard.unlock();
}

int main(void)
{
    std::jthread thr(Print, "abc");
    std::jthread thr1(Print, "def");
    std::jthread thr2(Print, "hij");
}
