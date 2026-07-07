//#include <iostream>
//#include <thread>
//#include <chrono>
//
//using namespace std::literals;
//
//
////NOTE: in this particluar case thread is slower than the main printing many times because os has to do work like assign it memory
//// give it its own memory so its atleast some expensive thing to do
//
//void Hello()
//{
//    // the actual function which is tied to the execution thread which is generated
//    // to actually join u need a reference to the thread object which is connected to it
//    //std::this_thread::sleep_for(std::chrono::seconds(2));
//    std::cout << "Hello world" << std::endl;
//    return;
//}
//
//void func(std::thread&& thr)
//{
//    std::cout << "Moved thread object id :"<<thr.get_id() << std::endl;
//    thr.join();
//}
//
//int main(void)
//{
//    std::thread thr(Hello);
//
//    // so thr is the thread obj
//    // this whole thing is the main execution
//
//    std::thread a = std::move(thr);
//
//    std::cout << "The Id of a :" << a.get_id() << std::endl;
//    func(std::move(a));
//
//}