//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <chrono>
//
//std::mutex mtx1;
//std::mutex mtx2;
//
//void func()
//{
//    std::cout << "Thread one tried to lock both mutexes" << std::endl;
//    std::scoped_lock lck(mtx1, mtx2);
//    std::cout << "Thread one has locked both mutexes" << std::endl;
//    std::cout << "Now there is no chance of deadlock" << std::endl;
//}
//
//void func2()
//{
//    using namespace std::literals;
//    std::this_thread::sleep_for(100ms);
//    std::cout << "Thread  two tried to lock both mutexes" << std::endl;
//    std::scoped_lock lck(mtx1, mtx2);
//    std::cout << "Thread two has locked both mutexes" << std::endl;
//    std::cout << "Now there is no chance of deadlock" << std::endl;
//}
//
//
//int main(void)
//{
//    std::jthread thr(func);
//    std::jthread thr2(func2);
//}