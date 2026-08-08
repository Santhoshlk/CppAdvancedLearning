//#include <iostream>
//#include <thread>
//#include <chrono>
//#include <future>
//
//using namespace std::literals;
//
//void Producer(std::promise<int>& px)
//{
//    try
//    {
//        std::cout << "The Producer thread started" << std::endl;
//        std::this_thread::sleep_for(2s);
//
//        // now throw an exception
//        throw std::out_of_range("Oops");
//    }
//    catch (const std::exception& e)
//    {
//        std::cout << "The Producer thread has thrown an exception" << std::endl;
//        px.set_exception(std::current_exception());
//    }
//}
//
//
//void Consumer(std::future<int>& f)
//{
//    std::cout << "The Consumer thread has started" << std::endl;
//
//    try
//    {
//        auto value = f.get();
//    }
//
//    catch (const std::exception& e)
//    {
//        std::cout << e.what() << std::endl;
//    }
//
//}
//
//int main(void)
//{
//
//    std::promise<int> p;
//    std::future<int> f = p.get_future();
//
//    std::jthread thr(Producer, std::ref(p));
//    std::jthread thr2(Consumer, std::ref(f));
//
//}