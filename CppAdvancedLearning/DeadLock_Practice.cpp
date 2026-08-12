#include <iostream>
#include <thread>
#include <mutex>


std::mutex mtx1;
std::mutex mtx2;

void func1()
{
    std::unique_lock lck1(mtx1, std::defer_lock);
    std::unique_lock lck2(mtx2, std::defer_lock);

    std::lock(lck1, lck2);

    // critical section
    std::cout << "There is now no possibility of deadlock" << std::endl;

    lck1.unlock();
    std::cout << "I unlocked the first lock of the thread 1" << std::endl;

    lck2.unlock();
    std::cout << "I unlocked the second lock of the thread 1" << std::endl;

}

void func2()
{
    std::unique_lock lck1(mtx1, std::defer_lock);
    std::unique_lock lck2(mtx2, std::defer_lock);

    std::lock(lck2, lck1);

    // critical section
    std::cout << "There is now no possibility of deadlock" << std::endl;

    lck1.unlock();
    std::cout << "I unlocked the first lock of the thread 2" << std::endl;

    lck2.unlock();
    std::cout << "I unlocked the second lock of the thread 2" << std::endl;
}

int main(void)
{
    std::jthread thr(func1);
    std::jthread thr2(func2);
}
