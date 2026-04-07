#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *str = new Zombie(name);
	return (str);
}