#include "Zombie.hpp"

Zombie::~Zombie() {
    std::cout << _name << " destroyed" << std::endl;
}

void Zombie::setName(const std::string &newName) {
    _name = newName;
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}