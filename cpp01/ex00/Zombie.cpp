#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie (std::string newName)
{
	name = newName;
}

Zombie::~Zombie()
{
	std::cout << name << " destroyed" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}