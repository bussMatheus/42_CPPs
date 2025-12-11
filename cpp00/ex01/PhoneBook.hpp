#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook {
	public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(const Contact &contact);
	void	searchContact(void) const;
	void 	displayContacts(int index) const;

	private:
	Contact	_contacts[8];
	int		_nextIndex;
	int		_contactCount;

	std::string _formatField(std::string str) const;
};

#endif