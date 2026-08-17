#include <iostream>
#include <random>

std::mt19937 eng;

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        std::uniform_int_distribution<int> ud(0, 10);
        std::cout << "The random number is :" << ud(eng) << std::endl;
    }

    for (int i = 0; i < 10; i++)
    {
        std::uniform_real_distribution<float> ud(0, 1);
        std::cout << "The random number is :" << ud(eng) << std::endl;
    }

}