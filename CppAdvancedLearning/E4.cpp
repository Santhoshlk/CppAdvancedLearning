#include <thread>
#include <mutex>
std::mutex mtx1;

int x{ 0 };

void func()
{
    while (x == 0)
    {
        std::lock_guard lck(mtx1);
       if(x!=1)
        x = 1 - x;
    }
}

void func2()
{
    while (x == 0)
    {
        std::lock_guard lck(mtx1);
        if (x != 1)
          x = 1 - x;
    }
}

int main(void)
{
    std::jthread thr(func);
    std::jthread thr2(func2);

}
