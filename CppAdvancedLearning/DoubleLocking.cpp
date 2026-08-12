// double locking consists of the phenomenon of preventing initalization data race by doing additional if checks
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
class Test
{
public:
    Test()
    {
        std::cout << "Constructor of Test Object is called" << std::endl;
    }
    void func(){}
};

Test* ptr = nullptr;

void Process()
{
    //lazy initialization
    if (!ptr)
    {
        std::unique_lock lck(mtx);
        if (!ptr)
        {
            ptr = new Test;
        }
        lck.unlock();
        ptr->func();
        // here there is no data race possibility
    }
}
int main(void)
{
    std::jthread thr(Process);
    std::jthread thr2(Process);
}

