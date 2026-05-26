//// Weapon Ownership Question
//
//#include <iostream>
//#include <string>
//
//using String = std::string;
//
//// Weapon class
//// weapon Name , int AttackPower
//
//class Weapon
//{
//private:
//	 const String m_Name;
//	int m_AttackPower;
//public:
//	Weapon(const String& Name, int AP) : m_Name(Name) , m_AttackPower(AP) {}
//
//	const String& GetName() const { return m_Name; }
//   
//	int GetAttackPower() const { return m_AttackPower; }
//
//	// Destructor for lifecycle purpose
//	~Weapon()
//	{
//		std::cout << "The Weapon Instance is destroyed\n";
//	}
//};
//
//
//// Senario 1-
//// The entity has the weapon the weapon is born and dies with the enitiy
//
//class Entity
//{
//private:
//	Weapon* weapon;
//	const String E_Name;
//	float E_Health;
//	const float E_MaxHealth;
//public:
//
//	Entity( Weapon*w,  const String& s,float h, float mh) : weapon(w) , E_Name(s) , E_Health(h) , E_MaxHealth(mh) {}
//
//	const String& GetEName() const { return E_Name; }
//
//	int GetoutDamage()
//	{
//		return (int)(E_Health / E_MaxHealth) * (weapon->GetAttackPower());
//	}
//
//	~Entity()
//	{
//		
//		std::cout << "The Object Instance of entity is destroyed\n";
//	}
//};
//
//// Senario 2:
//// the Weapon is with the world then enity dies but the world destroys the weapon
//
//
//
//int main()
//{
//	
//	// Senario 1
//	// The Copy Destructor of Weapon is called
//	// Entity destructor is called as u need the mebers to be alive
//	// The weapon Destructor is called
//	//Entity e(Weapon(std::string("Axe"),20), std::string("Santhosh"), 200.f, 500.f);
//
//	Weapon* a = new Weapon(std::string("Axe"), 20);
//
//
//	
//
//	Entity b(a, std::string("Santhosh"), 200.f, 500.f);
//
//	delete a;
//}