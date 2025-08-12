#include "Zombie.hpp"

Zombie::Zombie(std::string newName)
{
    name = newName;
}

Zombie::~Zombie()
{
    std::cout << name << " a été détruit" << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
