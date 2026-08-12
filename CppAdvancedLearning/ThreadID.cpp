#include <iostream>
#include <thread>

void Hello()
{
    // this thread can actually give the id to the thread executing this function code
    std::cout << "The thread ID of the thread executing this thread is :" << std::this_thread::get_id() << std::endl;
}

int main(void)
{
    std::cout << "Thread ID of main execution is :" << std::this_thread::get_id() << std::endl;

    std::thread thr(Hello);

    std::cout << "Thread ID of the child thread is :" << thr.get_id() << std::endl;

    thr.join();

    std::cout << "Thread ID of the child thread after joining is :" << thr.get_id() << std::endl;
}
