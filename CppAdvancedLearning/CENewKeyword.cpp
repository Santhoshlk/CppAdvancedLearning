//#include <iostream>
//#include <string>
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
//	Enemy(const String& s1) : m_Name(s1) {}
//
//	Enemy() :  m_Name("Unknown") {}
//
//	const String& GetName()  const { return m_Name; }
//
//
//};
//
//Enemy* enemy;
//
//int main()
//{
//	enemy = new Enemy("Santhosh");
//
//	int* b = new int;
//
//	// for an array
//	delete b;
//	b = new int[50];// int be 4 bytes so 200 bytes
//
//
//
//	delete []b;// if u allocated as an array through the new keyword
//
//	delete enemy;
//
//	// this type u just take default constructor
////	enemy = new Enemy[50];
//
//
//	// theoretically u can also use malloc
//	enemy = (Enemy*)malloc(sizeof(Enemy));
//
//	// but this has a major flaw that u cant call the constructor 
//	free(enemy);// u specifically do this when u use malloc
//
//}