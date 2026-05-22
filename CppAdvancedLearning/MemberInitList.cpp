#include <iostream>
#include <string>


// Memebr init list are a way to better initialize class members
// especially imp to have for having aliases and const in class members

class Enemy
{
	const int id;
	std::string Name;
	int& threatLevel;

public:

	Enemy(int a, const std::string& b, int& c) :id(a), Name(b), threatLevel(c) {};

	void Display() const
	{
		std::cout << "Id:" << id << std::endl;
		std::cout << "Name:" << Name << std::endl;
		std::cout << "ThreatLevel:" << threatLevel << std::endl;
    }
};

int main()
{
  std:: string a = "FrostBoss";
  int threat = 50;
	Enemy e(1, a, threat);
	e.Display();

  // Terinary Operator
	int s_speed = 5;
	int s_level = 10;

	s_speed = s_level > 5 ? 10 : 5;

	std::cout << s_speed << std::endl;
}