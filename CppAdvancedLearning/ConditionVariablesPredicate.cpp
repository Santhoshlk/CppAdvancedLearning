//#include <iostream>
//#include <string>
//#include <thread>
//#include <mutex>
//#include <chrono>
//#include <shared_mutex>
//#include <condition_variable>
//
//using namespace std::literals;
//
//// common mutex string variable bool predicate condition variable
//static std::string data_buffer = "";
//static std::shared_mutex mtx;
//static std::condition_variable_any cv;
//static bool condition = false;
//
//
//void reader()
//{
//    std::this_thread::sleep_for(1s);
//    std::cout << "The readers are locking the mutex";
//    std::shared_lock lck(mtx);
//
//    // u need to wait for writer but do it with predicate to avoid lost wakeup
//    cv.wait(lck, []() {return condition; });
//
//    // now this is the critical section print the data
//    std::cout << data_buffer << std::endl;
//}
//
//
//void writer()
//{
//    std::cout << "The writer thread is locking the mutex" << std::endl;
//
//    {
//        std::lock_guard lck(mtx);
//        data_buffer = data_buffer + "Condition_Variable";
//        // now update the predicate bool
//        condition = true;
//    }
//    // this unlocks the mutex and u can call notify to work the normal case
//    cv.notify_all();
//}
//
//int main(void)
//{
//    std::jthread thr1(writer);
//    std::jthread thr2(reader);
//    std::jthread thr3(reader);
//    std::jthread thr4(reader);
//    std::jthread thr5(reader);
//    std::jthread thr6(reader);
//}
