#include <iostream>
#include <string>

void inspect(int &x) // just takes lvales and prints
{
	std::cout << "L Value :" << x << std::endl;
	return;
}

void inspect(const int& a)// takes both lvalues and rvalues
{
	std::cout << " L value but const init :" << a << std::endl;
}

void inspect(int&& x) // takes an r value input a temp object 
{
	x = 5;
	std::cout << "takes an rvalue behaves like an l value" << x << std::endl;
}

int main(void)
{
	int a = 4;// l value u can keep
	int i = a; 
	// error 5 = a;u cannot assign anything to an r value
	const int c = 5;// l value u cannot reassign
	int& d = a;
	// error int& e = 5; 
	const int& f = c;
	i = 7;

	inspect(4);
	inspect(c);
	inspect(i);

}