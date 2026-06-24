#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- ClapTrap ---" << std::endl;
	ClapTrap	cl("CL4P-TP");
	cl.attack("dummy");

	std::cout << "\n--- ScavTrap construction (watch the chaining) ---" << std::endl;
	ScavTrap	sc("SC4V-TP");

	std::cout << "\n--- ScavTrap abilities ---" << std::endl;
	sc.attack("intruder");
	sc.takeDamage(30);
	sc.beRepaired(10);
	sc.guardGate();

	std::cout << "\n--- destruction (reverse order) ---" << std::endl;
	return (0);
}
