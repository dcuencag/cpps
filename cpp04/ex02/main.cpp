#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	// Animal is abstract now: `new Animal();` would not compile.
	// const Animal* impossible = new Animal();

	std::cout << "=== array of Animals (half Dog, half Cat) ===" << std::endl;
	const int	size = 4;
	Animal		*zoo[size];

	for (int i = 0; i < size / 2; i++)
		zoo[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		zoo[i] = new Cat();

	std::cout << std::endl << "=== sounds (polymorphism) ===" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << zoo[i]->getType() << ": ";
		zoo[i]->makeSound();
	}

	std::cout << std::endl << "=== delete as Animal ===" << std::endl;
	for (int i = 0; i < size; i++)
		delete zoo[i];

	return (0);
}
