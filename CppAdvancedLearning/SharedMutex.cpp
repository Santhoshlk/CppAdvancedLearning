#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <shared_mutex>

std::shared_mutex lck;

int x = 0;

void write()
{
    // this is a write function so u wanna block any other  threads
   // critical section
    std::lock_guard<std::shared_mutex> guard(lck);
    std::cout << "Locked the thread" << std::endl;
    ++x;

}

void read()
{
    // this is just a read so all the threads which are having this shared mutex should be able to read this value
    std::shared_lock<std::shared_mutex> guard(lck);
    using namespace std::literals;
    std::this_thread::sleep_for(500ms);
}

int main(void)
{
    std::vector<std::jthread> v;
    // now we are actually constructing the threads while pushing them so directly moving the rvalues no need std::move
    v.reserve(42);
    for (int i = 0; i < 20; i++)
    {
        v.emplace_back(std::jthread(read));
    }
    v.emplace_back(std::jthread(write));
    v.emplace_back(std::jthread(write));
    for (int i = 0; i < 20; i++)
    {
        v.emplace_back(std::jthread(read));
    }
}
