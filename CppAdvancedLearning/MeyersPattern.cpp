#include <iostream>
#include <thread>


//this is known as myers initialization
// when u initialize objects u have 4 choices 
//1)normal initialization
//2)myers intiialization
//3)double locking
//4)call once system on a lambda while doing lazy initialization
class Test
{
public:
    Test()
    {
        std::cout << "Constructor of Test Object is called" << std::endl;
    }
    void func() {}
};

Test& Process()
{
    static Test* p = new Test;
    std::cout << p << std::endl;
    return *p;
}

int main(void)
{
    std::jthread thr(Process);
    std::jthread thr2(Process);
}
