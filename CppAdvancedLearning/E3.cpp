//#include <iostream>
//#include <thread>
//
//using thread = std::thread;
//
//void GameSol(const char * Name, int num)
//{
//    if (num % 3 == 0 && num % 5==0)
//    {
//        std::cout << Name << "Says fizzbuzz" << std::endl;
//        return;
//    }
//    if (num % 3 == 0)
//    {
//        std::cout << Name << " Says fizz" << std::endl;
//        return;
//    }
//    else if (num % 5 == 0)
//    {
//        std::cout << Name << " Says buzz"<<std::endl;
//        return;
//    }
//    else
//    {
//        std::cout << Name << "Says " << num <<std::endl;
//        return;
//    }
//}
//
//int main(void)
//{
//    thread t1(GameSol,"Abdul",1);
//    t1.join();
//    thread t2(GameSol, "Bart", 2);
//    t2.join();
//    thread t3(GameSol,"Claudia",3);
//    t3.join();
//    thread t4(GameSol, "Barbie", 5);
//    t4.join();
//    thread t5(GameSol, "Santhosh", 15);
//    t5.join();
//}
