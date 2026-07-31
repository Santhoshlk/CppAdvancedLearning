#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::literals;

// global string everything needed to acess which is 
static std::string dataBuffer = "";

// two bools which were false
static bool progress_flag = false;
static bool completed_flag = false;

// three mutexes to protect shared data from read write data races to happen
std::mutex mtx1;
std::mutex mtx2;
std::mutex mtx3;

// three functions to make network data transfer work
//1)UpdateData
//2)ProgressBar
//3)ProcessData

void UpdateData()
{
    for (int i = 0; i <= 9; i++)
    {
        std::cout << "Data Transfer in Progress:" << std::endl;
        std::unique_lock lck(mtx1);
        // lock the first mutex then do the data buffer sixe increase
        dataBuffer = dataBuffer + "Block" + std::to_string(i);
        lck.unlock();
        // lock the mutex 2 and update the progress flag
        std::unique_lock lck2(mtx2);
        progress_flag = true;
        lck2.unlock();
        //now let the thread sleep for 1s so that the transfer takes space in adequate time
        std::this_thread::sleep_for(1s);

       
    }
    // as the for loop is completed the data transfer is completed so update the completed flagf
    // now lock the mutex 3 which is for the completed boolean 
    std::unique_lock lck3(mtx3);
    completed_flag = true;
    lck3.unlock();
}



void ProgressBar()
{
   // lock the mutex and check for the process flag
    while (true)
    {

        std::unique_lock lck(mtx2);
        while (!progress_flag)
        {
            lck.unlock();
            std::this_thread::sleep_for(100ms);
            lck.lock();
            // to break it u need the completed flag
            std::unique_lock lck3(mtx3);
            if (completed_flag)
            {
                break;
            }
            lck3.unlock();
        }
        std::unique_lock lck3(mtx3);
        if (completed_flag)
        {
            break;
        }
        lck3.unlock();
        // if progress flag is true the mutex will be locked 
        std::unique_lock lck2(mtx1);
        std::cout << "The Data BufferSize is " << dataBuffer.size() << "Bytes" << std::endl;
        lck2.unlock();
        progress_flag = false;
        lck.unlock();
    }

}
    

void ProcessData()
{

    std::unique_lock lck(mtx3);
    while (!completed_flag)
    {
        lck.unlock();
        std::this_thread::sleep_for(200ms);
        lck.lock();
    }
    // once the process is complete show the complete size of the transfered data
    std::unique_lock lck2(mtx1);
    std::cout<<"The total Data size is of"<<dataBuffer.size() << "Bytes" << std::endl;
    std::cout << "The transfered data:" << dataBuffer << std::endl;
   
}

int main(void)
{
    std::jthread thr(UpdateData);
    std::jthread thr2(ProgressBar);
    std::jthread thr3(ProcessData);

}