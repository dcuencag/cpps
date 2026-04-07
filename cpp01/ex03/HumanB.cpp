#include "Weapon.hpp"
#include "HumanB.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string str) : name(str)
{
	weapon = NULL;
}

void HumanB::attack()
{
	if (!weapon)
		std::cout << name << " has no weapon to attack with" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &type)
{
	weapon = &type;
}
