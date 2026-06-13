//// operator overloading
//
//#include <iostream>
//#include <cassert>
//
//struct vec2  // due to backward compatability of c structs are same as classes with public as default
//{
//
//	float x, y;
//  
//  vec2(float x,float y) : x(x),y(y) {}
//
//
//  float& operator[] ( int i) 
//  {
//	  assert( i >= 0 && i <= 1 && "The value of int must be in bounds");
//	  if (i == 0)
//	  {
//		  return this->x;
//	  }
//	  else
//	  {
//		  return this->y;
//	  }
//  }
//  
//  vec2& operator=(const vec2& a)  
//  {
//	  this->x = a.x;
//	  this->y = a.y;
//	  return *this;
//  }
//
//  vec2& operator+= (const vec2& a)
//  {
//	  this->x += a.x;
//	  this->y += a.y;
//	  return *this;
//	  // u return *this and refernec because u are doing something on this object instance
//  }
//
//  
//};
//
//// a struct so no need of friend in this case
//vec2 operator+(const vec2&a, const vec2&b)
//{
//	return vec2(a.x+b.x,a.y+b.y);
//}
//
//
//std::ostream& operator<<(std::ostream& stream, const vec2& a)
//{
//	stream << "x :" << a.x << " "<<"y :" << a.y<<"\n";
//	return stream;
//}
//
//bool operator==(const vec2& a, const vec2&b)
//{
//	return a.x == b.x && a.y == b.y;
//}
//vec2 operator-(const vec2& a, const vec2& b)
//{
//	return vec2(a.x - b.x, a.y - b.y);// just copy the damn object
//}
//
//
//int main()
//{
//	vec2 a{ 1.f,2.f }, b{ 2.f,3.f }, d{3.f,5.f};
//
//	// operator overloading of a+b
//	vec2 c = a + b;
//
//	// to print it just overload <<
//	std::cout << c;
//
//	if (c == d)
//	{
//		std::cout << "They both are equal" << std::endl;
//	}
//
//	std::cout << c[0] << std::endl;
//	c[0] = 5;
//
//	c += {2.f, 3.f};
//	std::cout << c;
//
//	vec2 e{ 1.f,3.f };
//	std::cout << c - e << std::endl;
//}