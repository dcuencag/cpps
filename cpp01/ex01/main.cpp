#include "Zombie.hpp"
#include <string>

int	main(void)
{
	int	n = 5;
	Zombie *HordeOfZombie = zombieHorde(n, "zombie");
	for (int i = 0; i < n; i++)
		HordeOfZombie[i].announce();
	delete[] HordeOfZombie;
	return 0;
}