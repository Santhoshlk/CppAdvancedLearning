#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <chrono>

using namespace std::literals;

// now create the atomic flag
std::atomic_flag flag = ATOMIC_FLAG_INIT;

// for this example critcal section is just std::cout

void func()
{
    while(flag.test_and_set())
    {
      
    }

    // critical section
        std::cout << "This is the thread with number" << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(500ms);
    // now critical is done have another thread take it
    flag.clear();
   
}

int main(void)
{
    std::vector<std::thread> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(std::thread(func));
    }
    for (auto& x : v)
    {
        // u got the reference of the thread obj
        x.join();
    }
}