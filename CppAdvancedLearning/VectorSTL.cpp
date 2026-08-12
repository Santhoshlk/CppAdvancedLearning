#include <iostream>
#include <string>
#include <vector>


void PrintSumProduct( const std::vector<int>& v)
{
	int sum = 0;
	int product = 1;

	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		product *= v[i];
	}

	std::cout << "The sum is :" << sum << std::endl;
	std::cout << "The product is " << product << std::endl;
}
 int main()
{
	//std::string name = "Santhosh"; // we copy a constant string which we can change
 // 
	//std::cout << name.length()<< std::endl;// length or size 
	//
	//
	//// two types of dclerations
	//std::vector<int> v;
	//std::vector<int> primes = {1,2,3,4,5}; // this is the general which is list initialiser
	//std::vector strings{"Santhosh" , "Sai" , "Nikhil"};// implicit decleration and identification of type at compile time
	//std::vector<int> v(3);


	//std::vector<int> primes{1,2,3,4,5};

	//for (int i = 0; i < primes.size(); i++)
	//{
	//	std::cout << &primes[i] << std::endl;
	//}
	//std::vector square{ 1,4,9,16,25 };//

	

	std::vector<int> a(3);
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << "Enter 3 integers :";
		std::cin >> a[i];
	}
	PrintSumProduct(a);


}
