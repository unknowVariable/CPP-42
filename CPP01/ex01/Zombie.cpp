#include "Zombie.hpp"

Zombie::Zombie() {
    name = "";
}

Zombie::~Zombie() {
    std::cout << name << " destroyed" << std::endl;
}

void Zombie::setName(const std::string &newName) {
    name = newName;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}