//// here we are gonna handroll an lock_guard class
//#include <iostream>
//#include <thread>
//#include <string>
//#include <mutex>
//#include <chrono>
//
//using namespace std::literals;
//
//std::mutex thread_lock;
//
//class Lock_guard
//{
//    std::mutex& mux;
//public:
//    explicit  Lock_guard(std::mutex& a) : mux(a) { mux.lock(); }
//
//    ~Lock_guard()
//    {
//        mux.unlock();
//    }
//};
//
//void func(std::string&& str)
//{
//    for (int i = 0; i < 5; i++)
//    {
//        try {
//            Lock_guard guard(thread_lock);
//
//            //critical section
//            std::cout << str[0] << str[1] << str[2] << std::endl;
//
//            // throw an exception
//            throw std::exception();
//
//            // u cant unlock here even though its not critical section
//            std::this_thread::sleep_for(100ms);
//        }
//        catch (const std::exception& e)
//        {
//            std::cout << "exception thrown" << std::endl;
//        }
//
//    }
//}
//
//
//int main(void)
//{
//    std::jthread thr(func, std::string("abc"));
//    std::jthread thr1(func, std::string("xyz"));
//    std::jthread thr2(func, std::string("def"));
//}