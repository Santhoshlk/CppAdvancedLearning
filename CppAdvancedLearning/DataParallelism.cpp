// first one by async
#include <iostream>
#include <future>
#include <vector>
#include <random>

std::mt19937 eng;

size_t sum(const std::vector<int>& v, int start, int end)
{
    size_t s = 0;
    for (int i = start; i <= end; i++)
    {
        s += v[i];
    }
    return s;
}

size_t Process(const std::vector<int>& v)
{
    // now what u can do is call std::async on all
   
    
        size_t v1 = v.size() / 4;
        auto f1 = std::async(std::launch::async, sum, std::cref(v), 0, v1 - 1);
        auto f2 = std::async(std::launch::async, sum, std::cref(v), v1, (2 * v1) - 1);
        auto f3 = std::async(std::launch::async, sum, std::cref(v), 2 * v1, 3 * v1 - 1);
        auto f4 = std::async(std::launch::async, sum, std::cref(v), 3 * v1, 4 * v1 - 1);

        size_t result = f1.get() + f2.get() + f3.get() + f4.get();
        return result;
}

void result(const std::vector<int>& v,const std::vector<int>& a)
{
     auto r1 = Process(v);
     auto r2 = Process(a);

     std::cout << "The sum of first 16 whole numbers is " << r1 << std::endl;
     std::cout << "The sum of 10000 random numbers is " << r2 << std::endl;
}

int main(void)
{
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
    result(v, a);

}

