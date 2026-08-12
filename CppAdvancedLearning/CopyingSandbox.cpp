// just a small concept and an small example for it

#include <iostream>

class Test
{
private:
	int* x;
	int buffer;
public:
	Test(int a) : x(new int[a]), buffer(a) {};
   
	Test(const Test& a)
	{
		int b = a.GetBuffer();
		x = new int[b];
		buffer = b;
    }

	int GetBuffer() const
	{
		return buffer;
	}

	~Test()
	{
		delete[]x;
		std::cout << " The instance of the Test is Destroyed" << std::endl;
	}
};


int main()
{
	Test a(5);
     
	Test b(a);

    std::cout<<	b.GetBuffer()<<std::endl;
}
