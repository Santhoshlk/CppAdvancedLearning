#include <iostream>
#include <thread>

static int a = 0;

void Update()
{
    for (int i = 1; i <= 100000; i++)
    {
        a++;
    }
    return;
}

int main(void)
{
    std::thread thr(Update);
    std::thread thr2(Update);
    std::thread thr3(Update);

    
    thr.join();
    thr2.join();
    thr3.join();


    std::cout << "The value of a :" << a << std::endl;
}
