#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
	type = "Cat";
}
Cat::Cat(const Cat &o) : Animal(o), brain(new Brain(*o.brain))
{
}
Cat &Cat::operator=(const Cat &o)
{
	if (this != &o)
	{
		Animal::operator=(o);
		*brain = *o.brain;
	}
	return (*this);
}
Cat::~Cat()
{
	delete	brain;
}
void Cat::makeSound() const
{
	std::cout << "Miaou! Miaou! Miaou! 🐱" << std::endl;
}
void Cat::setIdea(int i, const std::string &s)
{
	brain->setIdea(i, s);
}
std::string Cat::getIdea(int i) const
{
	return (brain->getIdea(i));
}
