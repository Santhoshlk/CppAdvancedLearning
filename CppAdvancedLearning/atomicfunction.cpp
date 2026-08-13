#include <iostream>
#include <atomic>

int main(void)
{
    std::atomic<int> x = 0;
    
    x.store(2);

    std::cout << "The value of x is :" << x.load() << std::endl;

    auto old = x.exchange(3);

    std::cout << "The old value of x is :" << old << std::endl;

    std::cout << "The value of x is " << x.load() << std::endl;


}