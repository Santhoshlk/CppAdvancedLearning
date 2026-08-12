#include <iostream>
#include <string>
#include <thread>

using thread = std::thread;

// pass by value (default case in the constructor
void PassByValue(std::string Name)
{
    Name = Name + " Lukka";
    std::cout << "PassByValue :" << Name << std::endl;
}


// pass by const ref

void ConstRef(const std::string& Name)
{
    std::cout << "ConstRef :" << Name << std::endl;
}

// pass by ref

void PassByRef(std::string& Name)
{
    Name = Name + " Lukka";
    std::cout << "Ref :" << Name << std::endl;
}

// pass by rvalue
void rvalue(std::string&& Name)
{
    std::cout << "Moved Rvalue ref :" << Name << std::endl;
}


int main(void)
{
    // lamdas
    int i = 5;

    thread t1([&i](int a) { std::cout << i * a << std::endl; }, 2);

    t1.join();

    //moving
    thread t2(rvalue, std::move(std::string("Santhosh")));
    t2.join();

    std::string a = "Santhosh";
    // pass by value
    thread t3(PassByValue, a);
    t3.join();

    std::cout << "A did not change " << a << std::endl;

    // pass by const ref
    thread t4(ConstRef, std::cref(a));
    t4.join();

    // pass by ref
    thread t5(PassByRef, std::ref(a));
    t5.join();
    std::cout << "A did  change " << a << std::endl;
}
