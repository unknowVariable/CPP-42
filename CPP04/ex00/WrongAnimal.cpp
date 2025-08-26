#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "[WrongAnimal] ctor" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &o) : type(o.type)
{
    std::cout << "[WrongAnimal] copy" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &o)
{
    if (this != &o)
        type = o.type;
    std::cout << "[WrongAnimal] assign" << std::endl;
    return *this;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] dtor" << std::endl;
}
const std::string &WrongAnimal::getType() const { return type; }
void WrongAnimal::makeSound() const
{
    std::cout << "🔊❓ (bruit bizarre inaudible)" << std::endl;
}
