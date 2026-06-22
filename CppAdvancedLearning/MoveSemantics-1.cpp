//#include <iostream>
//#include <cstring> 
//
//class String
//{
//private:
//	char* m_Buffer;
//	int m_size;
//public:
//	// normal constructor
//	String(const char* a)
//	{
//		std::cout << "Created" << std::endl;
//		m_size = strlen(a);
//		m_Buffer = new char[m_size+1];
//		memcpy(m_Buffer, a, m_size + 1);
//		// u are taking a string now creating a heap object
//	}
//
//	// copy constructor , destructor
//	String(const String& other)
//	{
//
//		std::cout << "Copied" << std::endl;
//		m_size = other.m_size;
//		m_Buffer = new char[m_size + 1];
//		memcpy(m_Buffer, other.m_Buffer, m_size + 1);
//		// u are taking a string now creating a heap object and creating a deep copy
//	}
//
//	~String()
//	{
//		delete[] m_Buffer;
//		std::cout << "The object instance of string is destroyed" << std::endl;
//	}
//
//	// this is for temporary obj of this strings ownership change
//	// this takes in an r value refernce
//	String(String&& temp) noexcept
//	{
//		std::cout << "Moved" << std::endl;
//		m_Buffer = temp.m_Buffer;// it points to there
//		m_size = temp.m_size;
//
//		// now we dont let the temp have the heap so it cant destroy it
//		temp.m_Buffer = nullptr;
//		temp.m_size = -1;
//	}
//
//	void print() const
//	{
//		std::cout << m_Buffer << std::endl;
//	}
//};
//
//
//
//class Entity
//{
//private:
//	String s;
//
//public:
//	// normal copy
//	Entity(const String& a) : s(a) {};
//
//	// temp obj ownership Exchange
//	Entity(String&& a) : s(static_cast<String&&>(a)) {};
//};
//
//int main()
//{
//	// permanent deep copy
//	 const String s = "Santhosh";
//	 const Entity a(s);
//
//	// temp object ownership exchange
//	Entity b("Santhosh");
//
//	Entity	a("Santhosh");
//
//
//	// i used spaces
//	const  int a1 = 5;
//	// i	used	tabs
//	 const int	b1	=	5;;
//
//}