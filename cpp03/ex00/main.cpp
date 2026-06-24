#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- construction ---" << std::endl;
	ClapTrap	robot("CL4P-TP");

	std::cout << "\n--- combat ---" << std::endl;
	robot.attack("training dummy");
	robot.takeDamage(4);
	robot.beRepaired(2);

	std::cout << "\n--- copy ---" << std::endl;
	ClapTrap	clone(robot);
	clone.attack("training dummy");

	std::cout << "\n--- drain energy ---" << std::endl;
	for (int i = 0; i < 12; i++)
		robot.attack("training dummy");

	std::cout << "\n--- destroy it ---" << std::endl;
	clone.takeDamage(100);
	clone.attack("training dummy");
	clone.beRepaired(10);

	std::cout << "\n--- destruction ---" << std::endl;
	return (0);
}
