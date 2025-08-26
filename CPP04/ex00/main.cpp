#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "--- Polymorphisme CORRECT ---" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << std::endl << "--- Polymorphisme INCORRECT ---" << std::endl;
    const WrongAnimal* wrong = new WrongCat();
    wrong->makeSound();
    delete wrong;

    return 0;
}
