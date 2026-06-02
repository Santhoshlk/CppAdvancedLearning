//#include <iostream>
//
//struct Vector
//{
//	int x, y;
//
//	Vector (): x(10) , y(20) {}
//
//};
//
//
//int main()
//{
//   // stack var and array initalization
//	int value = 10;
//	int array[5] = {1,2,3,4,5};
//	Vector vector;
//
//
//	// heap value allocation
//	Vector* hvector = new Vector();
//	int* hvalue = new int;
//	*hvalue = 10;
//
//	int* harray = new int [5];
//	harray[0] = 1;
//	harray[1] = 2;
//	harray[2] = 3;
//	harray[3] = 4;
//	harray[4] = 5;
//
//
//	// now u have to free the memory
//	delete hvector;
//	delete hvalue;
//	delete[] harray;
//
//}