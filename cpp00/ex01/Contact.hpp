#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();

	void setFirstName(const std::string &val);
	void setLastName(const std::string &val);
	void setNickname(const std::string &val);
	void setPhoneNumber(const std::string &val);
	void setDarkestSecret(const std::string &val);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

#endif
