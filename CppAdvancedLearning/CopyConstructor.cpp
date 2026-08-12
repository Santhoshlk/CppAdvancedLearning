#include <iostream>
#include <cstring> // cstring

class String
{
private:
	// string is character array
	char* m_String;
	int m_Buffer;
public:
	// normal constructor
	String(char* string, int Buffer) : m_String(string) , m_Buffer(Buffer) {}

	// Copy Constructor
	 String(const char* string)
	{
		m_Buffer = strlen(string)+1;
		m_String = new char[m_Buffer];
		// u cannot directly initalise a char* as const char* so u copy it 
		memcpy(m_String, string, m_Buffer);
	}


	void Print() const
	{
		for (int i = 0; i < m_Buffer - 1; i++)
		{
			std::cout << m_String[i] << std::endl;
		}
	}

	// u need to free the memory
	~String()
	{
		delete[] m_String;
		std::cout << "The Object Instance of String has been Destroyed" << std::endl;
	}
};

int main()
{
	String a = "Santhosh";
	 a.Print();
}
