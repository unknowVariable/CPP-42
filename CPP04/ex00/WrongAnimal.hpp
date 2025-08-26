#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>
#include <iostream>

class WrongAnimal {
  protected:
    std::string type;
  public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &);
    WrongAnimal &operator=(const WrongAnimal &);
    ~WrongAnimal();

    const std::string &getType() const;
    void makeSound() const;
};
#endif
