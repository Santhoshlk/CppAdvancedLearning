#include <iostream>
#include <thread>
#include <vector>


class Test;

Test* a;

class Test
{
public:
    Test()
    {
        std::cout << "The Object instance of test has been created" << std::endl;
    }

    void func()
    {
        std::cout << "func" << std::endl;
    }
    ~Test()
    {
        std::cout << "The Object instance of test has been destroyed" << std::endl;
    }
};

void func()
{
    static Test* ptr = new Test();
    std::cout << ptr << std::endl;
    a = ptr;
}

int main(void)
{
    std::vector<std::thread> v;
    for (int i = 0; i < 10; i++)
    {
        v.emplace_back(std::thread(func));
    }
    for (auto& i : v)
    {
        i.join();
    }

    delete a;
}