#pragma once
#include <iostream>

class Singleton
{
    static Singleton* str;
  
  
public:
  // delete copy assignment constructor and move assignment  and move constructor
    explicit Singleton(){}
    Singleton(const Singleton& s) = delete;
    Singleton& operator=(const Singleton& s) = delete;
    Singleton(Singleton&& s) = delete;
    Singleton& operator=(Singleton&& s) = delete;
};

