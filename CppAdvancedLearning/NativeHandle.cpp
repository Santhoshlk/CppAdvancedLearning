//#include <iostream>
//#include <thread>
//
//void Hello()
//{
//    // you cannot use this thread to get native handle
//}
//
//int main(void)
//{
//    // in mvsc compiler it will look like pointers
//    //  in mingw it will look like elements of an array
//
//    // so we use this for the thread child objects in main
//    std::thread thr(Hello);
//
//    std::cout << "The Native Handle for thread thr : " << thr.native_handle() << std::endl;
//
//    // u have to join the thread
//    thr.join();
//
//    // it will be null
//    std::cout << "The Native Handle for thread thr : " << thr.native_handle() << std::endl;
//}