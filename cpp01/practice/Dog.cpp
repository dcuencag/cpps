#include "Dog.hpp"
#include <iostream>

Dog::Dog(std::string newName)
{
	name = newName;
};

Dog::~Dog()
{
	std::cout << name << " destroyed" << std::endl;
};

std::string Dog::getName()
{
	return name;
};