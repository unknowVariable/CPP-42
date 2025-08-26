#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "[Animal] ctor" << std::endl;
}
Animal::Animal(const Animal &o) : type(o.type)
{
    std::cout << "[Animal] copy" << std::endl;
}
Animal &Animal::operator=(const Animal &o)
{
    if (this != &o)
        type = o.type;
    std::cout << "[Animal] assign" << std::endl;
    return *this;
}
Animal::~Animal()
{
    std::cout << "[Animal] dtor" << std::endl;
}
const std::string &Animal::getType() const { return type; }
void Animal::makeSound() const
{
    std::cout << "(animal generic sound)" << std::endl;
}
