#pragma once
#include "SingletonClass.h"
#include <vector>
#include <thread>
//  here we dont lock the static member initialization by mutex because it makes it expensive
Singleton* Singleton::str = nullptr;

Singleton& Task()
{
     static Singleton Single;
     std::cout << &Single << std::endl;
     return Single;
}


int main(void)
{
    std::vector<std::jthread> v;
    v.reserve(20);
    for (int i = 0; i < 20; i++)
    {
        v.push_back(std::jthread(Task));
    }
}
