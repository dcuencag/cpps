#include "Harl.hpp"

int	main(int ac, char **av)
{
	int i = 1;
	Harl harl;
	while (i < ac)
	{
		harl.complain(av[i]);
		i++;
	}
}