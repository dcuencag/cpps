#include "Zombie.hpp"
#include <string>

int	main(void)
{
	Zombie *aliZombie = newZombie("HEAP");
	aliZombie->announce();
	randomChump("STACK");
	delete(aliZombie);
	return 0;
}