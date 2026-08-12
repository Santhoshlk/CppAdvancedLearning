// int style allocator
#include <iostream>
#include <cstring>


unsigned int buffer = 100;
unsigned int offset = 0;
unsigned int* arena;

void* allocation(unsigned int size)
{
	if (offset + size <= buffer)
	{
		void* ptr = &arena[offset];
		offset += size;

		memset(ptr, 0, size*sizeof(unsigned int));// this works in raw bits so u need to scale like 2 elements so 2* sizeof(unisgned int)
		return ptr;
	}
	return nullptr;
}



int main()
{
	arena = new unsigned int[buffer];
	void* ptr = allocation(10);
	for (int i = 0; i < offset; i++)
	{
		std::cout << arena[i] << std::endl;
	}

	// delete it obviously
	delete[] arena;
}
