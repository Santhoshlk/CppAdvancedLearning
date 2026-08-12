#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1;
std::mutex mtx2;


// the best way to fix livelock is to actually do deadlock  avoidance correctly
void func()
{
    std::scoped_lock lck(mtx1, mtx2);
    std::cout << "Thread 1 has locked the mutexes" << std::endl;
}


void func2() {
    {
        
        std::scoped_lock lck(mtx2, mtx1);
        std::cout << "Thread 2 has locked the mutexes" << std::endl;
    }



