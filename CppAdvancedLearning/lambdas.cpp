//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//
//struct Inc
//{
//    int m_inc = 0;
//
//    auto makeIncrementation()
//    {
//        return [this]()
//            {
//                m_inc++;
//            }();
//    }
//};
//
//int main(void)
//{
//    //q1
//    auto fn = [](int a) { return a * a * a; };
//
//    std::cout << fn(4) << std::endl;
//
//    //q2 i predit u cant do because it is immutabe if u catch by value
//    //error
//    int threshold{ 50 };
//    //[threshold]() {
//       // threshold = 100;
//       // return;
//       // };
//
//    //q3) now that u captured it by refernce it will work
//    [&threshold]()
//        {
//            threshold = 100;
//        }
//    ();
//    std::cout << "threshold :" << threshold << std::endl;
//
//
//    //q5)
//    std::vector<int> v{ 4, 7, 2, 9, 1, 5, 8 };
//    int comparator{ 5 };
//
//    std::cout << std::count_if(v.begin(), v.end(), [comparator](int a) {return a > comparator; }) << std::endl;
//
//    // q6)
//    const  auto it = std::find_if(v.begin(), v.end(), [](int a) { return a % 2 != 0; });
//    std::cout << "The first odd number in the vector :" << *it << std::endl;
//
//
//    //q7) u can sort then using bool comparator
//    std::sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
//
//    for (auto x : v)
//    {
//        std::cout << x << " ";
//    }
//    std::cout << "\n";
//    //q8)
//    auto f2 = [](int a, int b)
//        {
//            return (double)a / b;
//        };
//    std::cout << f2(7, 2) << std::endl;
//
//
//    int x = 1, y = 2, z = 3;
//
//    std::cout << [=]() { return x + y + z; }() << std::endl;
//
//    std::cout << [&]() {
//        x = y = z = 100;
//        return x + y + z;
//        }() << std::endl;
//
//    Inc a;
//    a.makeIncrementation();
//    std::cout << a.m_inc << std::endl;
//}