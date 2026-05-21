// Player class
#include <iostream>
#include <string>

class Player
{
	std::string m_Name;
	int m_Health;
	// yeah this should be const
	const int m_MaxHealth = 500;

public:
	// constructor
	Player( const std::string & a,int b)
	{
		m_Name = a;
		m_Health = b;
	}

	//Methods
	const std::string& GetName() const
	{
		return m_Name;
	}

	int GetHealth()const
	{
		return m_Health;
	}

	int GetMaxHealth() const
	{
		return m_MaxHealth;
	}

	void Damage(int dmg)
	{
		m_Health -= dmg;
	}

	double GetHealthPercentage() const
	{
		return (double)m_Health / m_MaxHealth;
	}


	// set Name
	void SetName(const std::string& name)
	{
    	this->m_Name = name;
	}
};

void Print(Player& P, int dmg)
{
	std::cout << "Before Damage:\n" << std::endl;
	std::cout << P.GetMaxHealth() << std::endl;
	std::cout << P.GetName() << std::endl;
	std::cout << P.GetHealth() << std::endl;
	std::cout << P.GetHealthPercentage() << std::endl;
	P.Damage(dmg);
	std::cout << "After Damage:\n" << std::endl;
	std::cout << P.GetMaxHealth() << std::endl;
	std::cout << P.GetName() << std::endl;
	std::cout << P.GetHealth() << std::endl;
	std::cout << P.GetHealthPercentage() << std::endl;

}

int main()
{

	std::string a = "Santhosh";
	Player P(a, 300);

	Print(P, 150);

	const Player P1(a, 200);
	// No Error
	std::cout << P1.GetMaxHealth() << std::endl;
	std::cout << P1.GetName() << std::endl;
	std::cout << P1.GetHealth() << std::endl;
	std::cout << P1.GetHealthPercentage() << std::endl;

	//// now error
	//P1.SetName(a);
	//P1.Damage(200);

	//// normal string storage
 //  std::string b = P1.GetName();
 //  const  std::string c = P1.GetName();
 //  // now Error
 //  std::string& d = P1.GetName();



}