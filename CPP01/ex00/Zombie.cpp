#include "Zombie.hpp"

Zombie::Zombie(std::string newName)
{
    _name = newName;
}

Zombie::~Zombie()
{
    std::cout << _name << " a été détruit" << std::endl;
}

void Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
