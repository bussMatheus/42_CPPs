#include "./PhoneBook.hpp"

void	handleAdd(PhoneBook &pb, Contact &c)
{
    std::string f, l, n, p, s;

	std::cout << "First Name: ";
	if (!std::getline(std::cin, f))
		return ;
	std::cout << "Last Name: ";
	if (!std::getline(std::cin, l))
		return ;
	std::cout << "Nickname: ";
	if (!std::getline(std::cin, n))
		return ;
	std::cout << "Phone Number: ";
	if (!std::getline(std::cin, p))
		return ;
	std::cout << "Darkest Secret: ";
	if (!std::getline(std::cin, s))
		return ;
	c.setContact(f, l, n, p, s);
	pb.addContact(c);
	return;
}

void	handleSearch(PhoneBook &pb)
{
	int			index;
	std::string input;

	index = 0;
	pb.searchContact();
	std::cout << "Enter Index: ";
	if(!std::getline(std::cin, input))
		return ;
	if (!input.empty() && std::isdigit(input[0]))
	{
		index = atoi(input.c_str());
		pb.displayContacts(index);
	}
	if (!std::isdigit(input[0]))
		std::cout << "Invalid. Try a digit between 0 and 9." << std::endl;
}

int	main(void)
{
	PhoneBook	pb;
	Contact		c;
	std::string	input;

	while (1)
	{
		std::cout << "Enter a Command (ADD, SEARCH, EXIT): ";
		if(!std::getline(std::cin, input))
			break ;
		if (input == "ADD")
			handleAdd(pb, c);
		else if (input == "SEARCH")
			handleSearch(pb);
		else if (input == "EXIT")
			break ;
	}
	return 0;
}
