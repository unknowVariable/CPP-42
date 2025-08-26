#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
}
AAnimal::AAnimal(const AAnimal &o) : type(o.type)
{
}
AAnimal &AAnimal::operator=(const AAnimal &o)
{
	if (this != &o)
		type = o.type;
	return (*this);
}
AAnimal::~AAnimal()
{
}
const std::string &AAnimal::getType() const
{
	return (type);
}
