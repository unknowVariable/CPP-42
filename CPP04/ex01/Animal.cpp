#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
}
Animal::Animal(const Animal &o) : type(o.type)
{
}
Animal &Animal::operator=(const Animal &o)
{
	if (this != &o)
		type = o.type;
	return (*this);
}
Animal::~Animal()
{
}
const std::string &Animal::getType() const
{
	return (type);
}
void Animal::makeSound() const
{
	std::cout << "(generic animal)" << std::endl;
}
