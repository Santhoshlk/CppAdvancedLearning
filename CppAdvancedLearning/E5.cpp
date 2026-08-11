//#include <iostream>
//#include <atomic>
//#include <thread>
//#include <mutex>
//
//std::mutex mtx;
//
//class Test
//{
//public:
//    Test()
//    {
//        std::cout << "The object of test is constructed" << std::endl;
//    }
//    ~Test()
//    {
//        std::cout << "The object instance of Test is destroyed" << std::endl;
//    }
//};
//
//// here we want to do it manual checking instead of thread safe initialization
//std::atomic<Test*> ptr = nullptr;
//
//void func()
//{
//    if (!ptr)// atomic read
//    {
//        std::lock_guard lck(mtx);
//
//        // correct sequence execution
//        if (!ptr) // atomic read
//        {
//            ptr = new Test();
//        }
//    }
//}
//
//int main(void)
//{
//    std::thread thr(func);
//    std::thread thr2(func);
//
//    thr.join();
//    thr2.join();
//
//    // why thread instead of jthread to delete the object
//    delete ptr;
//
//}