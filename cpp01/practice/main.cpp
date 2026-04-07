#include "Dog.hpp"
#include <iostream>

int	main(void)
{
	Dog *dogB = new Dog("heap");
	{
		Dog dogA("STACK");
		std::cout << dogA.getName() << std::endl;
		std::cout << dogB->getName() << std::endl;
	}
	std::cout << "end of main" << std::endl;
	delete dogB;
	return 0;
}