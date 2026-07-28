//// this is the process of intializing variables when every u wanna use
//#include <mutex>
//#include <thread>
//
//std::mutex mtx;
//
//class Test
//{
//public:
//    void func() {}
//};
//
//Test* ptr = nullptr;
//
//void Process()
//{
//    std::unique_lock<std::mutex> lck(mtx);
//
//    if (!ptr)
//    {
//        ptr = new Test;
//    }
//    lck.unlock();
//    ptr->func();
//}