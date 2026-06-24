#include <iostream>
#include <vector>

class Enemy
{
    int m_level;

public:
    Enemy(int a): m_level(a){
        std::cout << "Created" << std::endl;
    
    }
    
    // copy constructor
    Enemy(const Enemy& other) :m_level(other.m_level)
    {
        std::cout << "Copied" << std::endl;
    }

    // move constructor
    Enemy(Enemy&& other) noexcept
    {
        m_level = other.m_level;
        other.m_level = 0;
        std::cout << "Moved" << std::endl;
    }

    ~Enemy()
    {
        std::cout << "Object Instance of Enemy Destroyed!" << std::endl;
    }
};

int main()
{
    Enemy a = 10;
    Enemy b = 20;

    std::vector<Enemy> v;
    v.reserve(3);
    v.emplace_back((30));
    v.emplace_back((20));
    v.emplace_back(std::move(a));
    v.emplace_back(std::move(b));
}