#include <iostream>
#include <cassert>

// template classes


template<typename T, size_t N>
class array
{

    T arr[N];
public:

    T& at(int a)
    {
        assert("Out of bounds" && a >= 0 && a < N);
        return arr[a];
    }
    T& operator[](int a)
    {
        assert("Out of bounds" && a >= 0 && a < N);
        return arr[a];
    }
    T& front()
    {
        return arr[0];
    }
    T& back()
    {
        return arr[N - 1];
    }
    T* data()
    {
        // u can return because arr stays alive yeah cool dude
        return &arr[0];
    }
    size_t Size()
    {
        return N;
    }
    // here i assume the most normal thing iterator is a pointer
    T* begin()
    {
        return &arr[0];
    }
    T* end()
    {
        return arr + N;
    }
    const T* cbegin() const
    {
        return &arr[0];
    }
    const T* cend() const
    {
        return arr + N;
    }
    bool empty()
    {
        return (N == 0);
    }
    void fill(T a)
    {
        for (size_t i = 0; i < N; i++)
        {
            arr[i] = a;
        }
    }
    void Print()
    {
        for (size_t i = 0; i < N; i++)
        {
            std::cout << arr[i] << std::endl;
        }
    }
};



int main(void)
{

    array<int, 10> a;
    a.fill(1);
    a.Print();

    // should come runtime error
    //a.at(10);

    if (a.empty())
    {
        std::cout << "Is empty" << std::endl;
    }

    a[4] = 4;

    std::cout << a[4] << std::endl;
    std::cout << "The size of a :" << a.Size() << std::endl;
}
