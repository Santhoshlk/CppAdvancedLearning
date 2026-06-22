#include <iostream>
#include <cstring> 

class String
{
private:
	char* m_Buffer;
	int m_size;
public:
	// normal constructor
	String(const char* a)
	{
		std::cout << "Created" << std::endl;
		m_size = strlen(a)+1;
		m_Buffer = new char[m_size];
		memcpy(m_Buffer, a, m_size);
		// u are taking a string now creating a heap object
	}

	// copy constructor , destructor
	String(const String& other)
	{

		std::cout << "Copied" << std::endl;
		m_size = other.m_size;
		m_Buffer = new char[m_size];
		memcpy(m_Buffer, other.m_Buffer, m_size);
		// u are taking a string now creating a heap object and creating a deep copy
	}

	~String()
	{
		delete[] m_Buffer;
		std::cout << "The object instance of string is destroyed" << std::endl;
	}

	// this is for temporary obj of this strings ownership change
	// this takes in an r value refernce
	String(String&& temp) noexcept
	{
		std::cout << "Moved" << std::endl;
		m_Buffer = temp.m_Buffer;// it points to there
		m_size = temp.m_size;

		// now we dont let the temp have the heap so it cant destroy it
		temp.m_Buffer = nullptr;
		temp.m_size = 0;
	}
	

	// the move assignment for when both are equal
	String& operator=(String&& other) noexcept
	{
		if (this != &other)
		{
			delete[] this->m_Buffer;

			std::cout << "Moved" << std::endl;
			this->m_Buffer = other.m_Buffer;
			this->m_size = other.m_size;

			other.m_Buffer = nullptr;
			other.m_size = 0;
		}
		return *this;
	}


	// for copy assignment
	String& operator=(const String& other)
	{
		std::cout << "Copy Assignment" << std::endl;

		// u are copying so delete original
		if (this != &other)
		{
			delete[] m_Buffer;

			this->m_size = other.m_size;

			this->m_Buffer = new char[m_size];
			memcpy(this->m_Buffer,other.m_Buffer,this->m_size);
		}
		return *this;

	}


	void print() const
	{
		std::cout << m_Buffer << std::endl;
	}
};



class Entity
{
private:
	String s;

public:
	// normal copy
	Entity(const String& a) : s(a) {};

	// temp obj ownership Exchange
	Entity(String&& a) : s(static_cast<String&&>(a)) {};
};

int main()
{
	//// permanent deep copy
	//const String s = "Santhosh";
	//const Entity a(s);

	//// temp object ownership exchange
	//Entity b("Santhosh");

	//Entity	a("Santhosh");


	//// i used spaces
	//const  int a1 = 5;
	//// i	used	tabs
	//const int	b1 = 5;;

	// so create a string
         String a = "Santhosh";
	     String dest("");

		 std::cout << "a :";
	a.print();

	// both exist so do move a to d so covert a into an rvalue by std::move
	dest = std::move(a);
	std::cout << "a :";
		//a.print();
		std::cout << "dest :";
	dest.print();


	String c = "Apple";
	c = dest;
	std::cout << "c:";
	c.print();


}