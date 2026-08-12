#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>

using namespace std::literals;

class Vector
{
    std::mutex guard;
    std::vector<int> v;

public:
    void push_back(int a)
    {
        //evry thread executing the object works on v
        // its a good thing to lock it 
        guard.lock();
        v.push_back(a);
        guard.unlock();
    }

    void Print()
    {
        // u lock the read so that the read does not read when writing
        guard.lock();

        for (auto it = v.begin(); it != v.end(); it++)
        {
            std::cout << *it << ",";
        }
        guard.unlock();
    }
};

void func(Vector& v)
{
    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
        std::this_thread::sleep_for(50ms);
        v.Print();
    }
}

int main()
{
    Vector v;

    std::jthread thr(func, std::ref(v));
    std::jthread thr2(func, std::ref(v));
    std::jthread thr3(func, std::ref(v));

}
