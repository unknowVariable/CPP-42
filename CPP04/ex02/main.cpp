#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // AAnimal a; // interdit: classe abstraite (méthode pure virtuelle)

    AAnimal a;
    AAnimal* d = new Dog();
    AAnimal* c = new Cat();

    d->makeSound(); // Wouf!
    c->makeSound(); // Miaou!

    delete d;
    delete c;
    return 0;
}
