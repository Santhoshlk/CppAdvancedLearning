#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

std::atomic<int> count = 0;


void func()
{
    for (int i = 0; i < 10; i++)
    {
        count++;
    }
}

int main()
{

    std::vector<std::thread> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(std::thread(func));
    }

    for (auto& j : v)
    {
        j.join();
    }
    //here u have to use thread instead of jthread to print the value of count

    std::cout << "The value of count :" <<
        count << std::endl;
}
