//#include <iostream>
//#include <cstring>
//#include <cassert>
//
//static  char NULL_Address = '\0';
//
//// we make string class with deep copy
//class String
//{
//private:
//	 char* m_String;
//	unsigned int m_Buffer;
//public:
//explicit 	String( const char* s) 
//
//	{
//		// you have to create the heap object first 
//		m_Buffer = strlen(s);
//		m_String = new char[m_Buffer + 1];
//		memcpy(m_String, s, m_Buffer + 1);
//
//	}
//
//  // copy constructor
//	String(const String& copy) : m_Buffer(copy.m_Buffer)
//	{
//		// after that happens do the deep copy
//		std::cout << "Copy has been Done." << std::endl;
//		// u should not count \0 in size
//		m_String = new char[m_Buffer+1];
//		//copy the string
//		memcpy(m_String, copy.m_String, m_Buffer + 1);
//
//	}
//  
//	char& operator[] ( unsigned int index)
//	{
//		assert(index < m_Buffer && "The Index is out of bounds"); // assert crashes the program in debug mode
//		return m_String[index];
//	}
//
//	void Print() const
//	{
//		std::cout << m_String << std::endl;
//	}
//
//	// obviously the Destructor
//	~String()
//	{
//		std::cout<<"The Object Instance is Destroyed" << std::endl;
//		delete[]m_String;
//	}
//	
//};
//
//int main(void)
//{
//	 const String First("Santhosh");
//	 String Second = First; // i did not keep explicit
//	 Second[(unsigned int)1] = 's';
//   
//	 First.Print();
//	 Second.Print();
//}