#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1;
std::mutex mtx2;


void func()
{
    bool locked = false;

    while (!locked)
    {
        std::unique_lock lck(mtx1);
        std::cout << "Hello Thread 1" << std::endl;
        locked = mtx2.try_lock();
    }
    if (locked)
    {
        std::cout << "Thread 1 has locked both the mutexes" << std::endl;
        mtx2.unlock();

    }
}


void func2() {
    bool locked = false;

    while (!locked)
    {
        std::unique_lock lck(mtx2);
        std::cout << "Hello Thread 2" << std::endl;
        locked = mtx1.try_lock();
    }
    if (locked)
    {
        std::cout << "Thread 2 has locked both the mutexes" << std::endl;
        mtx1.unlock();
    }
}

int main(void)
{
    std::jthread thr(func);
    std::jthread thr2(func2);
}
