#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nextIndex(0), _contactCount(0) {}
PhoneBook::~PhoneBook(void) {}

void PhoneBook::addContact(const Contact &contact) {
	_contacts[_nextIndex] = contact;
	_nextIndex = (_nextIndex + 1) % 8;
	if (_contactCount < 8)
		_contactCount++;
}

std::string PhoneBook::_formatField(std::string str) const{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	PhoneBook::searchContact(void) const{
	if (_contactCount == 0) {
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	std::cout	<< std::setw(10) << "Index"		<< "|"
				<< std::setw(10) << "First Name"<< "|"
				<< std::setw(10) << "Last Name"	<< "|"
				<< std::setw(10) << "Nickname"	<< std:: endl;
	for (int i = 0; i < _contactCount; i++) {
		std::cout	<< std::setw(10) << i << "|"
					<< std::setw(10) << _formatField(_contacts[i].getFirstName()) << "|"
					<< std::setw(10) << _formatField(_contacts[i].getLastName()) << "|"
					<< std::setw(10) << _formatField(_contacts[i].getNickname()) << std::endl;
	}
}

void	PhoneBook::displayContacts(int index) const {
	if (index < 0 || index >= _contactCount) {
		std::cout << "invalid index." << std::endl;
		return ;
	}
	std ::cout	<< "First Name: " 		<< _contacts[index].getFirstName() << std::endl;
	std ::cout	<< "Last Name: "		<< _contacts[index].getLastName() << std::endl;
	std ::cout	<< "Nickname: " 		<< _contacts[index].getNickname() << std::endl;
	std ::cout	<< "Phone Number: " 	<< _contacts[index].getPhone() << std::endl;
	std ::cout	<< "Darkest Secret: "	<< _contacts[index].getSecret() << std::endl;
}
