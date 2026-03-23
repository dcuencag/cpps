#include "Contact.hpp"

Contact::Contact() {}

void Contact::setFirstName(const std::string &val) { firstName = val; }
void Contact::setLastName(const std::string &val) { lastName = val; }
void Contact::setNickname(const std::string &val) { nickname = val; }
void Contact::setPhoneNumber(const std::string &val) { phoneNumber = val; }
void Contact::setDarkestSecret(const std::string &val) { darkestSecret = val; }

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }
