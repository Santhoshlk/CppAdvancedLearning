// this is week 2 start
// arrow operation how it works internally and how do we use it find offset in variables
#include <iostream>
#include <memory>

class Entity
{
private:
	int m_Health;
public:
	Entity(int a) : m_Health(a) {}

	void Print() const { std::cout << "Health: " << m_Health << std::endl; }

	~Entity()
	{
		std::cout << "The object instance of entity is destroyed" << std::endl;
	}

};

struct vector3
{
	float x, y, z;
};

int main(void)
{
	std::unique_ptr< const Entity> entity = std::make_unique<Entity>(100);

	// to print 
	entity->Print();

	// u can also use as the function is const ur not modifiying the object 
	(*entity).Print();

	entity.reset();// destroy the instance

	entity = nullptr;

	int offsetx = (int)&((vector3*)nullptr)->x;// should be at 0
	std::cout << "the offset of x :" << offsetx << std::endl;

	int offsety = (int)&((vector3*)nullptr)->y;// should be at 4
	std::cout << "the offset of y :" << offsety << std::endl;

  int offsetz  = (int)&((vector3*)nullptr)->z;// should be at 8
  std::cout << "the offset of z :" << offsetz << std::endl;
}
