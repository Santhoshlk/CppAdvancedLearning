//// this is to show that data interlaving can happen while we are constructing an object of an thread class
//#include <iostream>
//#include <vector>
//#include <thread>
//#include <chrono>
//
//using namespace std::literals;
//class Base;
//std::vector<Base*> v;
//
//
//
//class Base
//{
//    public:
//    Base()
//    {
//        // technically when the constructor runs the vtable is constructed so we can pass this 
//        // as this becomes valid
//        v.push_back(this);
//    }
//  
//    virtual void Print()
//    {
//        std::cout << "Base class object" << std::endl;
//    }
//
//};
//
//class Derived : public Base
//{
//   public:
//    Derived()
//    {
//        v.pop_back();
//        v.push_back(this);
//    }
//
//    void Print() override 
//    {
//        std::cout << "Derived class object" << std::endl;
//    }
//};
//
//void func1()
//{
//    // it calls the derived class constructor
//    Derived d;
//    std::this_thread::sleep_for(100ms);
//   
//}
//void func2()
//{
//    if (!v.empty())
//    {
//        // so if the thread dosent interleave it reads the derived if it does it reads the base
//        for (int i = 0; i < 100; i++)
//        {
//            v[0]->Print();
//        }
//        
//    }
//   
//}
//
//int main()
//{
//    std::jthread thr(func1);
//    std::jthread thr2(func2);
//}