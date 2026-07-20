//// we are doing recursive mutex
//#include <iostream>
//#include <thread>
//#include <mutex>
//
//std::recursive_mutex rmutex;
//
//int recursion(int n)
//{
//
//    if (n <= 1)
//    {
//        return 1;
//    }
//
//    // we are aproaching critical section
//    std::lock_guard<std::recursive_mutex> lck(rmutex);
//    int rval = n * recursion(n - 1);
//
//    std::cout << "the return value :" << rval << std::endl;
//
//    return rval;
//
//}
//
//
//
//int main(void)
//{
//    std::jthread thr(recursion, 5);
//    std::jthread thr2(recursion, 6);
//}