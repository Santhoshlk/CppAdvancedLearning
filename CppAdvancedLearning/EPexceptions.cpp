#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>

namespace se = std::execution;


int main(void)
{

    std::vector<int> v{1,3,4,5,7,6,8,9};

    try
    {
        std::sort(se::par_unseq, v.begin(), v.end(), [](int a, int b)
            {
                throw std::out_of_range("OOps");
                return true;
            });
    }

    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    };

}