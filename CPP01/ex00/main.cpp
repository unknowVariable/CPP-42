#include "Zombie.hpp"

int main()
{
    Zombie *heapGuy = newZombie("Francis (heap)");
    heapGuy->announce();
    delete heapGuy;

    randomChump("Patrick (stack)");

    return (0);
}