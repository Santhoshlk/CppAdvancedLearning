//// this is for templates
//#include <iostream>
//#include <string>
//
//// we use templates to create a sort of blueprint that our compiler follows
//template<typename T>
//void Print(const T& value)
//{
//	std::cout << value << std::endl;
//}
//
//// these function are created at compile time
//// so u can actually give values at compile time for example c style lets make out owns std::Array
//
//template<typename T, int N>
//class Array
//{
//private:
//	T m_array[N];
//
//public:
//	int GetSize() const
//	{
//		return N;
//	}
//};
//
//
//int main()
//{
//	Print(5);
//	Print(5.5);
//	Print(5.5f);
//	Print('c');
//	Print("Santhosh");
//
//
//
//	//Print<std::string>(std::string("Santhosh"));
//
//	Array<int, 5> array;// gets made compile time so we need to give constants no runtime inputs std::cin not alloweed
//
//	std::cout << array.GetSize() << std::endl;
//}
//
//
//// this is for templates
//#include <iostream>
//#include <string>
//
//// we use templates to create a sort of blueprint that our compiler follows
//template<typename T>
//void Print(const T& value)
//{
//	std::cout << value << std::endl;
//}
//
//// these function are created at compile time
//// so u can actually give values at compile time for example c style lets make out owns std::Array
//
//template<typename T, int N>
//class Array
//{
//private:
//	T m_array[N];
//
//public:
//	int GetSize() const
//	{
//		return N;
//	}
//};
//
//
//int main()
//{
//	Print(5);
//	Print(5.5);
//	Print(5.5f);
//	Print('c');
//	Print("Santhosh");
//
//
//
//	//Print<std::string>(std::string("Santhosh"));
//
//	Array<int, 5> array;// gets made compile time so we need to give constants no runtime inputs std::cin not alloweed
//
//	std::cout << array.GetSize() << std::endl;
//}
//
//
