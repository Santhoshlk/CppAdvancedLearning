#include <iostream>
#include <chrono>

namespace sc = std::chrono;

using namespace std::literals;


int main(void)
{
	sc::seconds(5); // this is an input u can give if anyone asks for 5 sec
	sc::milliseconds(10); // this is an input u can give where u want milliseconds
	sc::microseconds(2);
	sc::nanoseconds(3);
	
	//2s;
	//4ms;
	//50us; by dumping that namespace u can use these directly

}
