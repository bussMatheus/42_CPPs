#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

void Contact::setContact(std::string first, std::string last,
						std::string nick, std::string phone, std::string secret)
{
	_firstName = first;
	_lastName = last;
	_nickname = nick;
	_phoneNumber = phone;
	_darkestSecret = secret;
}

std::string Contact::getFirstName(void) const { return _firstName; }
std::string Contact::getLastName(void) const { return _lastName; }
std::string Contact::getNickname(void) const { return _nickname; }
std::string Contact::getPhone(void) const { return _phoneNumber; }
std::string Contact::getSecret(void) const { return _darkestSecret; }