#include <iostream>
#include <vector>
#include <algorithm>
#include <atomic>
#include <execution>

namespace se = std::execution;

int main(void)
{
    std::vector<int> v{1,3,2,4,6,9,7,8};

    ////// sort it first using seq
    ////std::sort(se::seq,v.cbegin(),v.cend());



    //// sort it using unseq
    //std::sort(se::unseq, v.cbegin(), v.cend());

    ////  no data race in Parallel due to atomic
    //std::vector<int> v(100000, 0);

    //std::atomic<int> count = 0;
    //std::for_each(se::par, v.begin(), v.end(), [&count](int &x) {  x = ++count;  });

   

    //std::cout << v[v.size() - 1] << std::endl;

    std::sort(se::par_unseq,v.begin(),v.end());

    // the biggest perfomance gain of the bunch

    for (auto& i : v)
    {
        std::cout << i << ",";
    }
}