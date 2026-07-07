//#include <iostream>
//#include <chrono>
//#include <thread>
//
//using namespace std::literals;
//
//void Hello(int a)
//{
//    // put the thread  to sleep
//    std::this_thread::sleep_for(2s);
//    // u wont get completely unrecognisable calls because cout is synchronized per call
//    std::cout << "My name is santhosh " << a << std::endl;
//}
//
//int main()
//{
//    std::jthread t1(Hello, 1);
//    t1.join();
//    std::jthread t2(Hello, 2);
//    t2.join();
//    std::jthread t3(Hello, 3);
//    t3.join();
//}
