#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std::literals;

void Print(const std::string& Message)
{
    std::this_thread::sleep_for(3s);
    std::cout << Message << std::endl;
}

int main(void)
{
    std::jthread thr(Print, std::string("This is Hard"));
}