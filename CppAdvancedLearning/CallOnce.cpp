#include <iostream>
#include <thread>

class Test
{
public:
    Test()
    {
        std::cout << "Constructor of Test Object is called" << std::endl;
    }
    void func() {}
};

Test* ptr = nullptr;
std::once_flag flag;

void Process()
{
    std::call_once(flag,
        []()
        {
            ptr = new Test;
        }
    );
    std::cout << ptr << std::endl;
}

int main(void)
{
    std::jthread thr(Process);
    std::jthread thr2(Process);
}
