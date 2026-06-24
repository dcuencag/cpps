#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "--- ScavTrap ---" << std::endl;
	ScavTrap	sc("SC4V-TP");
	sc.attack("intruder");
	sc.guardGate();

	std::cout << "\n--- FragTrap construction (watch the chaining) ---" << std::endl;
	FragTrap	fr("FR4G-TP");

	std::cout << "\n--- FragTrap abilities ---" << std::endl;
	fr.attack("dummy");
	fr.takeDamage(40);
	fr.beRepaired(15);
	fr.highFivesGuys();

	std::cout << "\n--- destruction (reverse order) ---" << std::endl;
	return (0);
}
