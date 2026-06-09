#include <iostream>


struct Entity
{
	virtual ~Entity()
	{
		std::cout << "The Object instance of entity is destroyed" << std::endl;
	}
};

struct Player : public Entity
{
	static void levelup()
	{

	}

	~Player() override
	{
		std::cout<<"The Object Instance of Player is Destroyed "<<std::endl;
	}
};

struct Goblin : public Entity
{
	static void Screech()
	{

   }
	~Goblin() override
	{
		std::cout << "The object Instance of Goblin is Dead" << std::endl;
	}
};


int main(void)
{
	//int a {(int)"hello"}; // cstyle check n compile time check dangerous

	//int a{ static_cast<int>("Hello") };

	// start writing using this {} truncated does not allow bad data and more proffesional

	//int a{ 40 };
	//char ch{ static_cast<char>(a) }; // compiler will give u warning as this can overflow


	//q1) static cast data loss is ok
	double dmg{ 76.38 };
	int damage{ static_cast<int>(dmg) }; // here static cast is okay as we need the int conversion so data loss is okay

	std::cout << "The value of Damage is :" << damage << std::endl;

	//q2)int to double
	// safe
	int score{ 5 };
	double d_score{ static_cast<double>(score) }; // int fits in double
	std::cout << "The value of d_score is : " << d_score << std::endl;

	//q3)upcast perfectly safe no need of judegment
	//Player* a = new Player();
	//Entity* b = a; // its safe

	// q4)down cast  but be safe keep caution here okay
	Entity* a = new Player();
	Player* b = static_cast<Player*>(a);
	b->levelup();
	delete b; // now a will become dangling

	//q5)dynamic_cast this for down casting
	Entity* c = new Player();
	 const Goblin* d = dynamic_cast<Goblin*>(c);
	// this will give a null pointer
	if (!d)
	{
		std::cout << "The Dynamic Cast works uhu" << std::endl;
	}
	else
	{
		d->Screech();
	}

	//q6)void if u do malloc u can type cast to int
	

	// q7) c style cast  with truncated do not allow loss of data
	  //double to int not allowd
	//int v{ {int }dmg };
}