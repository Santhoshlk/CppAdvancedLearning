////compile time programming 
//
//#include <iostream>
//#include <array>
//
//constexpr int Factorial(int n)
//{
//	int a = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		a *= i;
//	}
//	return a;
//}
//
//
//int main()
//{
//	constexpr int a = 5;
//
//
//	// it guarentees no error because we can get the size at compiletime
//
//	//const cannot guarrentee the compile tiem as it can hold 
//
//	// some array size for suppose
//	constexpr int arraysize = a;
//
//	std::array<int, arraysize> array;
//
//	for (int i = 0; i < array.size(); i++)
//	{
//		std::cin >> array[i];
//	}
//	for (int i = 0; i < array.size(); i++)
//	{
//		std::cout << array[i] << " ";
//	}
//
//
//	// constexpr as a function says that if u pass compile time values u will get the answer at compile time
//   // if u pass the values any of the arguments at runtime u will get the values at runtime haha
//
//	constexpr int f1 = Factorial(5);// guarenteed complie time
//	std::cout << "CompileTime :" << f1<<std::endl;
//
//
//	  int n;
//     std::cin >> n;
//	 int f2 = Factorial(n);// this is rumtime
//	 std::cout << "Runtime :" << f2 << std::endl;
//}
