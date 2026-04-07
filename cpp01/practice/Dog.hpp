#ifndef DOG_HPP
#define DOG_HPP
#include <string>

class Dog
{
	private:
		std::string name;
	public:
		Dog(std::string newName);
		~Dog();
		std::string	getName();
};

#endif
