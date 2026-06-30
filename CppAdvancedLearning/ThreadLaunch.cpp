#include <iostream>
#include <string>
#include <thread>


void Name(const char* Name)
{
	std::cout << "My name is :" << Name << std::endl;
	return;
}

struct Enemy
{
	std::string m_Name;
	explicit Enemy(const std::string& a) : m_Name(a) {}
   
	void operator()()
	{
		std::cout << m_Name << std::endl;
	}

	void Print()
	{
		std::cout << "Print :" << m_Name << std::endl;
	}
};




int main(void)
{
	std::thread t(Name,"Santhosh");

	std::thread t2([](int args) {std::cout << args << std::endl; },3);

	// main should wait foir the execution otherwise the thread obj gets destroyed and program gets terminated
	// created and they join and they can join in any order
	t.join();
	t2.join();

	// now these both are done lets create third thread
	Enemy n(std::string("Santhosh"));
	std::thread  t3(n);
	t3.join();

	// now t3 will always join after t and t2

	Enemy n2 ( std::string("Cherno"));
	std::thread t4(&Enemy::Print, &n2);
	t4.join();
}