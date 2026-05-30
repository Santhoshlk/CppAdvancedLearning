//// this where the Mini Projects Start
//// this will be done after watching the video of cherno
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <memory>
//
//// Ability Effect 
//// it contains members Name , Magnitude
//
//class AbilityEffect
//{
//private:
//	std::string m_Name;
//	int m_Magnitude;
//public:
//	AbilityEffect(const std::string& name, int magnitude) : m_Name(name) , m_Magnitude(magnitude) {}
//     
//
//	const std::string& GetName() const { return m_Name;  }
//	int GetMagnitude() const { return m_Magnitude; }
//
//  // setters
//	void SetName(const std::string& Name)
//	{
//		m_Name = Name;
//	}
//
//	void SetMagnitude(int magnitude)
//	{
//		m_Magnitude = magnitude;
//	}
//
//	// Destructor just to show what happens
//	~AbilityEffect()
//	{
//		std::cout << "Object Instance of Ability Effect is Destroyed\n";
//
//	}
//};
//
//// 2) Struct Stats
//
//struct Stats
//{
//	//public by default
//	int Health;
//	int Armour;
//
//	Stats(int a , int b) : Health(a) , Armour(b) {}
//   
//	void print() const
//	{
//		std::cout << "Health:" << Health << std::endl;
//		std::cout << "Armour:" << Armour << std::endl;
//	}
//};
//
//// 3)Entity class
//
//class Entity
//{
//private:
//	// u need a unique ptr as when entity gets destroyed the Ability effect needs to so ucannot share it to other ref
//	std::unique_ptr<AbilityEffect> m_Effect;
//	Stats Currentstat;
//	std::string E_Name;
//public:
//	Entity(std::unique_ptr<AbilityEffect> e,  const Stats& stat, const std::string& name) : m_Effect(std::move(e)), Currentstat(stat), E_Name(name) {}
//	
//	Entity(const Stats& stat, const std::string& name) :Currentstat(stat) , E_Name(name) {}
//   // for ability system u need to get the unique ptr
//	 std::unique_ptr<AbilityEffect> GetCurrentEffect()  { return std::move(m_Effect);  }
//
//	 // set Current Effect
//	 void SetCurrentEffect(std::unique_ptr<AbilityEffect> e) {
//		 m_Effect = std::move(e);
//	 }
//
//	 const Stats& GetCurrentStats() const { return Currentstat; }
//	 ~Entity()
//	 {
//		 std::cout << "The Object Instance of Entity is Destroyed\n";
//	 }
//};
//
//
//void Transfer(std::shared_ptr<Entity> a , std::shared_ptr<Entity> b)
//{
//	auto au = a->GetCurrentEffect();
//	auto bu = b->GetCurrentEffect();
//	bu = std::move(au);
//
//	std::cout<<bu->GetName()<<std::endl;
//	std::cout << bu->GetMagnitude() << std::endl;
//	b->SetCurrentEffect(std::move(bu));
//   
//}
//
//// Global vector of Entity called Ability system Component
//// it dosent own them so its called by weak ptr
//std::vector<std::weak_ptr<Entity>> AbilitySystemComponent;
//
//
//void Print(const std::vector<std::weak_ptr<Entity>>& ASC)
//{
//	if (ASC.empty())
//	{
//		return;
//	}
//	for (std::weak_ptr<Entity> a : ASC)
//	{
//		if (auto ae = a.lock())
//		{
//			const Stats& CS = ae->GetCurrentStats();
//			CS.print();
//		}
//		else
//		{
//			continue;
//		}
//	}
//}
//
//int main()
//{
//	// make three effects and their Entity
//	// u need to use them Globally so make then in heap and  u need to use weak ptr so make them shared
//	auto  ae = std::make_unique<AbilityEffect>(std::string("GE_Rage"), 20);
//	auto  ce = std::make_unique<AbilityEffect>(std::string("GE_TargetLock"), 40);
//
//		// as these are unique_ptr u cannot send them as refernce and the const wrapps around smart pointer wrapper so its unnecesary and also wrong
//	   // so every time u need o send it as move because u are giving the refernce out
//       auto a = std::make_shared<Entity>(std::move(ae),Stats(20,30),std::string("Character 1"));
//       auto b = std::make_shared<Entity>(Stats(30, 40), std::string("Character 2"));
//	   auto c = std::make_shared<Entity>(std::move(ce), Stats(40, 50), std::string("Character 3"));
//
//	   // now just add them to ASC
//	   AbilitySystemComponent.push_back(a);
//	   AbilitySystemComponent.push_back(b);
//	   AbilitySystemComponent.push_back(c);
//
//
//	   Transfer(a, b);
//
//	   Print(AbilitySystemComponent);
//
//	   // now as c will have only one shared ptr referebce resetting it will destroy it
//	   c.reset();
//
// }