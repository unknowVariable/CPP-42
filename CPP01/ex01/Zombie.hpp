#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie();
    ~Zombie();

    void setName(const std::string &newName);
    void announce() const;
};

Zombie* zombieHorde(int N, std::string name);

#endif