#include <iostream>
#include <string>

void Print( const std::string& a)
{
	std::cout << "l value :" << a << std::endl;
}

void Print(std::string&& a)
{
	std::cout << "r values :" << a << std::endl;
}


int main(void)
{
	std::string firstname = "Santhosh";
	std::string lastname = "Lukka";
	std::string totalname = firstname + lastname;


	Print(totalname);
	Print(firstname + lastname);
}
