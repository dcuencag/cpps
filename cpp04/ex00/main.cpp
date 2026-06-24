#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Polymorphism (Animal) ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "---" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // cat sound
	j->makeSound(); // dog sound
	meta->makeSound();

	std::cout << std::endl << "=== WrongAnimal (no virtual) ===" << std::endl;
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << "---" << std::endl;
	std::cout << wc->getType() << " " << std::endl;
	wc->makeSound(); // WrongAnimal sound, NOT WrongCat's
	wa->makeSound();

	std::cout << std::endl << "=== cleanup ===" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wa;
	delete wc;
	return (0);
}
