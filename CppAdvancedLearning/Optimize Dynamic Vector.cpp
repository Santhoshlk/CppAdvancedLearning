#include <iostream>
#include <vector>

struct Vector3
{
	int x, y, z;

	Vector3(int a, int b,int c) : x(a) , y(b) , z(c) {}

	Vector3(const Vector3& vector)
	{
		std::cout << "Copied!" << std::endl;
	}
};


int main()
{
	// to make a dynamic array that grows we use std::vector to not waste memory
	std::vector<Vector3> vector;

	// completely unoptized code 10 copies 
	//vector.push_back(Vector3(1, 2, 3));
	//vector.push_back(Vector3(4 ,5, 6));
	//vector.push_back(Vector3(7 , 8 , 9));
	//vector.push_back(Vector3(10 , 11 ,12));

	// Parially optimzed 4 copies
	// here we stoped copies of reallocation
	//vector.reserve(4); // we made vector size big enough to hold 4 copies //  but the copying we did not stop
	//vector.push_back(Vector3(1, 2, 3));
	//vector.push_back(Vector3(4 ,5, 6));
	//vector.push_back(Vector3(7 , 8 , 9));
	//vector.push_back(Vector3(10 , 11 ,12));



	// completely optimzed code no copied saves a lot of permorance oer multiple objects
	// we use emplace_back
	vector.reserve(4); 
	vector.emplace_back(Vector3::Vector3(1,2,3));
	vector.emplace_back(3,4,5);
	vector.emplace_back(6,7,8);
	vector.emplace_back(9,10,11);


	

}