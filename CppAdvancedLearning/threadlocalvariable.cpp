//#include <iostream>
//#include <string>
//#include <thread>
//
//thread_local std::string str;
//
//void func1(const std::string& s)
//{
//    str = s;
//    std::cout << str << std::endl;
//}
//
//void func2(const std::string& s)
//{
//    str = s;
//    std::cout << str << std::endl;
//}
//
//int main(void)
//{
//    std::string a = "Santhosh";
//    std::string b = "Ranyard";
//
//    std::jthread thr(func1, std::cref(a));
//    std::jthread thr2(func2, std::cref(b));
//
//}