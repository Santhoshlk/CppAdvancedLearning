#include <iostream>
#include <thread>

// safe thread class
// its a hand rolled jthread
class ScopedThread
{
    std::thread thr;
public:

    // move constructor the give the ownership to the thread object
    explicit  ScopedThread(std::thread&& a) : thr(std::move(a)) {}

    // destructor
    ~ScopedThread()
    {
        if (thr.joinable()) // that means by the scope of execution this object dies the execution thread is alive so we need to wait for it
        {
            thr.join();
            // now what ever called the thread joins or waits for it so the object can die
        }

        std::cout << "The Scoped thread object died" << std::endl;
    }

};

void Hello()
{
    std::cout << "The Execution Thread Handle" << std::this_thread::get_id() << std::endl;
}

int main()
{
    try
    {
        ScopedThread a(std::move(std::thread(Hello)));

        // now a has ownership
        throw 8;

    }
    catch (int e)
    {
        std::cout << "The execption has been thrown" << std::endl;
    }
//}
