#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) { type = "Cat"; }
Cat::Cat(const Cat &o) : AAnimal(o), brain(new Brain(*o.brain)) {}
Cat &Cat::operator=(const Cat &o)
{
    if (this != &o)
    {
        AAnimal::operator=(o);
        *brain = *o.brain;
    }
    return *this;
}
Cat::~Cat() { delete brain; }
void Cat::makeSound() const { std::cout << "Miaou! Miaou! Miaou! 🐱" << std::endl; }
