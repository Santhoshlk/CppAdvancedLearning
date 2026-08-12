// Algorithm call with predicate
// Using lambda expression
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> vec{ 4, 2, 3, 5, 1 };

    std::cout << "Elements of vector: ";

    for (auto i : vec)
        std::cout << i << ", ";
    std::cout << '\n';
    int a;
    std::cout << "Enter the number to check divisibility :";
    std::cin >> a;


    // Call std::count_if() algorithm using a lambda expression as predicate
    auto n_divisibility = std::count_if(vec.begin(), vec.end(),


        // The lambda definition goes inside the call!
        [&a](int n)
        {
            return (n % a == 0);
        }
    );

    std::cout << "The vector has " << n_divisibility << " element(s) with given divisibility  values\n";
}   
