#include <iostream>
#include <memory>
#include <string>
#include <utility>


enum class EInvestmentTypes : int8_t
{
    Stock,
    Bond,
    RealEstate
};

using String = std::string;
class Investment
{
public:
    virtual  ~Investment()
    {
        std::cout << "The Object Instance of Investment is Destroyed" << std::endl;
    }
};

class Stock : public Investment
{
public:
    ~Stock() override
    {
        std::cout << "The Object Instance of Stock is Destroyed" << std::endl;
    }
};

class Bond : public Investment
{
public:
    ~Bond() override
    {
        std::cout << "The Object Instance of Bond is Destroyed" << std::endl;
    }
};

class RealEstate : public Investment
{
public:
    ~RealEstate() override
    {
        std::cout << "The Object Instance of RealEstate is Destroyed" << std::endl;
    }
};

auto deletefn = [](Investment* ptr)
    {
        std::cout << "The pointer is Destroyed" << std::endl;
        delete ptr;
    };



std::unique_ptr<Investment, decltype(deletefn)> MakeInvestment(EInvestmentTypes Choice) // Need further lessons on syntax
{
    // first declare an unique ptr
    std::unique_ptr<Investment, decltype(deletefn)> Ptr(nullptr, deletefn);

    switch (Choice)
    {
    case EInvestmentTypes::Stock:
        Ptr.reset(new Stock());
        break;
    case EInvestmentTypes::Bond:
        Ptr.reset(new Bond());
        break;
    case  EInvestmentTypes::RealEstate:
        Ptr.reset(new RealEstate());
        break;
    default:
        Ptr.reset(new Investment());
        break;
    }

    return std::move(Ptr);
}


int main(void)
{
    auto a = MakeInvestment(EInvestmentTypes::Stock);// the delete function is called once per the object
}
