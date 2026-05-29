//// this work on cascading
//#include <iostream>
//
//class Transform
//{
//private:
//	int x, y, rotation;
//	float scale;
//public:
//	Transform()
//	{
//
//	}
//	Transform(int x, int y, int rotation, float scale)
//	{
//		// i generally learned that init lists are better but here we are using this
//		this->x = x;
//		this->y = y;
//		this->rotation = rotation;
//		this->scale = scale;
//	}
//
//  // setters as getters u can't give the reference
//  // *this is necessary otherwise . cascading is not possible
//     Transform& SetPosition(int x, int y)
//	{
//		this->x = x;
//		this->y = y;
//		return *this;
//	}
//
//	Transform& SetRotation(int rotation)
//	{
//		this->rotation = rotation;
//		return *this;
//	}
//
//	Transform& SetScale(float scale)
//	{
//		this->scale = scale;
//		return *this;
//	}
//
//	void Print() const
//	{
//		std::cout << " X , Y :" << x << " : " << y << std::endl;
//		std::cout << "Rotation" << rotation << std::endl;
//		std::cout << "Scale" << scale << std::endl;
//
//		return;
//	}
//	int Getx() const
//	{
//		return this->x;
//	 }
//};
//
//int main()
//{
//	Transform a;
//	//cascading
//	a.SetPosition(100, 50).SetRotation(90).SetScale(2.0f).Print();
//	a.Getx();
//
//}