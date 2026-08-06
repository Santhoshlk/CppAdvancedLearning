//#include <iostream>
//#include <string>
//#include <thread>
//#include <chrono>
//#include <mutex>
//#include <shared_mutex>
//
//
//using namespace std::literals;
//std::string data_buffer = "";
//
//std::shared_mutex mtx;
//
//bool condition = false;
//void func1()
//{
//    // this is thread a 
//    std::cout << "Thread has started" << std::endl;
//
//    std::shared_lock lck(mtx);
//
//    std::cout << "Thread  has locked the mutex" << std::endl;
//
//    // here in the critical section u need the data to be updated by thread 2
//    // so u need to release the mutex under the condition that the bool is false
//
//    while (!condition)
//    {
//        lck.unlock();
//        std::this_thread::sleep_for(1s);
//        lck.lock();
//    }
//
//
//    // after it returns it automatically locks the mutex so u can read here
//    std::cout << "The data value is :" << data_buffer << std::endl;
//}
//
//void func2()
//{
//    // let this sleep for 500ms
//    std::this_thread::sleep_for(500ms);
//
//    std::cout << "Thread 2 has started" << std::endl;
//
//    std::unique_lock lck(mtx);
//
//    std::cout << "Thread 2 has locked  the mutex" << std::endl;
//
//
//    std::cout << "Thread 2 is updating the data" << std::endl;
//
//    std::this_thread::sleep_for(100ms);
//
//    condition = true;
//    data_buffer = "Condition_Variables";
//
//
//    lck.unlock();
//    //as all the threads that are waiting need to be notified
//    std::cout << "All the threads that are waiting are given the updated data:" << std::endl;
//
//}
//
//int main(void)
//{
//    std::jthread thr1(func1);
//    std::jthread thr2(func1);
//    std::jthread thr3(func1);
//    std::jthread thr4(func1);
//    std::jthread thr5(func1);
//
//
//    std::jthread thr6(func2);
//}