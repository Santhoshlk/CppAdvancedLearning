// now this for complie time classes or structs 
#include <iostream>

class Vec2
{
	int m_x, m_y;

public:
	constexpr Vec2(int a, int b) :m_x(a), m_y(b) {}
	constexpr int GetX() const { return m_x; }
	constexpr int GetY() const { return m_y; }

	
};


constexpr Vec2 operator+(const Vec2&v1 ,const Vec2& v2) // this being const makes sure it works for runtime to
{
	return Vec2(v1.GetX()+v2.GetX(),v1.GetY()+v2.GetY());
}
int main()
{
	constexpr Vec2 a(2, 3);
	constexpr Vec2 b(3, 4);

	// so the assert works
	static_assert(b.GetX() == 3 , "The value is  not found out at compile time");

	constexpr Vec2 c = a + b;


	// so the assert works
	static_assert(c.GetX() == 5 ,  "The value is not  found out at compile time");


	// this code gives error perfectly for the static assert  so its dobe at runtime 
	//int r1, r2;
	//std::cin >> r1 >> r2;

	//Vec2 d(r1,r2);
	//static_assert(d.GetX() ,  "The value is  not found out at compile time");

}
