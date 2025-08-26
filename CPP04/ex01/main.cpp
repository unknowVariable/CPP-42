#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int N = 4;
    Animal *zoo[N];
    for (int i = 0; i < N; ++i)
    {
        if (i % 2)
            zoo[i] = new Dog();
        else
            zoo[i] = new Cat();
    }
    for (int i = 0; i < N; ++i)
        zoo[i]->makeSound();

    Dog dog1;
    dog1.setIdea(0, " Balle rouge ");
    Dog dog2 = dog1;
    dog2.setIdea(0, " Balle bleue "); 

    std::cout << "dog1[0]=" << dog1.getIdea(0) << ", dog2[0]=" << dog2.getIdea(0) << std::endl;

    for (int i = 0; i < N; ++i)
        delete zoo[i];
    return 0;
}
