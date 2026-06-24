#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
	std::cout << "=== array of Animals (half Dog, half Cat) ===" << std::endl;
	const int		size = 4;
	Animal			*zoo[size];

	for (int i = 0; i < size / 2; i++)
		zoo[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		zoo[i] = new Cat();

	std::cout << std::endl << "=== sounds ===" << std::endl;
	for (int i = 0; i < size; i++)
		zoo[i]->makeSound();

	std::cout << std::endl << "=== delete as Animal ===" << std::endl;
	for (int i = 0; i < size; i++)
		delete zoo[i];

	std::cout << std::endl << "=== deep copy test ===" << std::endl;
	Dog	original;
	original.getBrain()->setIdea(0, "bones");

	Dog	copy(original);
	copy.getBrain()->setIdea(0, "cats");

	std::cout << "original idea[0]: " << original.getBrain()->getIdea(0)
		<< std::endl;
	std::cout << "copy idea[0]    : " << copy.getBrain()->getIdea(0)
		<< std::endl;
	std::cout << "brains differ?  : "
		<< (original.getBrain() != copy.getBrain() ? "yes (deep copy)" : "no (shallow!)")
		<< std::endl;

	std::cout << std::endl << "=== assignment deep copy test ===" << std::endl;
	Cat	a;
	a.getBrain()->setIdea(0, "tuna");
	Cat	b;
	b = a;
	b.getBrain()->setIdea(0, "milk");
	std::cout << "a idea[0]: " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "b idea[0]: " << b.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "=== cleanup (stack objects) ===" << std::endl;
	return (0);
}
