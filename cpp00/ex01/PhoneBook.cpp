#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : count(0), oldest(0) {}

void PhoneBook::addContact(const Contact &contact)
{
	contacts[oldest] = contact;
	oldest = (oldest + 1) % 8;
	if (count < 8)
		count++;
}

int PhoneBook::getCount() const { return count; }

static std::string truncate(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

static void printField(const std::string &label, const std::string &value)
{
	std::cout << label << value << std::endl;
}

void PhoneBook::searchContacts() const
{
	if (count == 0) {
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}

	std::cout << std::right
		<< std::setw(10) << "index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << std::endl;

	for (int i = 0; i < count; i++) {
		std::cout << std::right
			<< std::setw(10) << i << "|"
			<< std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
			<< std::setw(10) << truncate(contacts[i].getLastName()) << "|"
			<< std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
	}

	std::cout << "Enter index: ";
	std::string input;
	std::getline(std::cin, input);
	if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos) {
		std::cout << "Invalid index." << std::endl;
		return;
	}

	int idx = std::atoi(input.c_str());
	if (idx < 0 || idx >= count) {
		std::cout << "Index out of range." << std::endl;
		return;
	}

	printField("First name:     ", contacts[idx].getFirstName());
	printField("Last name:      ", contacts[idx].getLastName());
	printField("Nickname:       ", contacts[idx].getNickname());
	printField("Phone number:   ", contacts[idx].getPhoneNumber());
	printField("Darkest secret: ", contacts[idx].getDarkestSecret());
}
