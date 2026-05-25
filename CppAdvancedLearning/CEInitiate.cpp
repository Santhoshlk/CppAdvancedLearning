//#include <iostream>
//#include <string.h>
//
//using String = std::string;
//
//class Enemy
//{
//private:
//	String m_Name;
//public:
//
//	// u can give may types of membered init lists
//	Enemy(const String& s1) : m_Name(s1) {};
//
//	Enemy() :  m_Name("Unknown") {};
//
//	const String& GetName()  const { return m_Name; }
//
//
//};
//
//void Fun()
//{
//	Enemy enemy("Santhosh");
//	const String& s1 = enemy.GetName();
//	// the string lifetime dies after u go out of the function
//}
//
//// This is a Global class u can create a object anywhere 
//
//int main()
//{
//	//{
//	//	Enemy enemy("Santhosh");
//	//}
//	//// Now that this is a stack object the memory holding in it would be released and destructor is called
//	//// so the reference goes away and u cant acces it
//	////stack objcets liketime only remains untill scope
//	//std::cout << enemy.GetName() << std::endl;
//}