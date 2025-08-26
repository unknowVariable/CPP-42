#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
	type = "Dog";
}
Dog::Dog(const Dog &o) : Animal(o), brain(new Brain(*o.brain))
{
}
Dog &Dog::operator=(const Dog &o)
{
	if (this != &o)
	{
		Animal::operator=(o);
		*brain = *o.brain;
	}
	return (*this);
}
Dog::~Dog()
{
	delete	brain;
}
void Dog::makeSound() const
{
	std::cout << "Wouf! Wouf! Wouf! 🐶" << std::endl;
}
void Dog::setIdea(int i, const std::string &s)
{
	brain->setIdea(i, s);
}
std::string Dog::getIdea(int i) const
{
	return (brain->getIdea(i));
}
