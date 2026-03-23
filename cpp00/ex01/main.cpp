#include "PhoneBook.hpp"
#include <iostream>
#include <string>

static std::string promptField(const std::string &prompt)
{
	std::string value;
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, value);
		if (!value.empty())
			return value;
		std::cout << "Field cannot be empty." << std::endl;
	}
}

static void addContact(PhoneBook &pb)
{
	Contact c;
	c.setFirstName(promptField("First name: "));
	c.setLastName(promptField("Last name: "));
	c.setNickname(promptField("Nickname: "));
	c.setPhoneNumber(promptField("Phone number: "));
	c.setDarkestSecret(promptField("Darkest secret: "));
	pb.addContact(c);
	std::cout << "Contact added." << std::endl;
}

int main()
{
	PhoneBook pb;
	std::string cmd;

	while (true) {
		std::cout << "> ";
		if (!std::getline(std::cin, cmd))
			break;
		if (cmd == "ADD")
			addContact(pb);
		else if (cmd == "SEARCH")
			pb.searchContacts();
		else if (cmd == "EXIT")
			break;
	}
	return 0;
}
