#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) { type = "Dog"; }
Dog::Dog(const Dog &o) : AAnimal(o), brain(new Brain(*o.brain)) {}
Dog &Dog::operator=(const Dog &o)
{
    if (this != &o)
    {
        AAnimal::operator=(o);
        *brain = *o.brain;
    }
    return *this;
}
Dog::~Dog() { delete brain; }
void Dog::makeSound() const { std::cout << "Wouf! Wouf! Wouf! 🐶" << std::endl; }
