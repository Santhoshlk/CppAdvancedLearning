#include <iostream>
#include <future>
#include <thread>
#include <random>
#include <vector>

std::mt19937 eng;



 

int main(void)
{

    // sum func
    auto fn = [](const std::vector<int>& v, int start, int end)
        {
            int s = 0;
            for (int i = start; i <= end; i++)
            {
                s += v[i];
            }
            return s;
        };


    std::vector<int> v;
    for (int i = 0; i < 16; i++)
    {
        v.push_back(i);
    }

    std::vector<int> a;
    std::uniform_int_distribution<int> ud(1, 10000);
    for (int i = 0; i < 10000; i++)
    {
        a.push_back(ud(eng));
    }

 

}