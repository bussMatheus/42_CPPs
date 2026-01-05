#include "utils.hpp"

bool	is_validnum(std::string p)
{
	if (p.empty())
	{
		std::cout << "Error. Empty field." << std::endl;
		return (false);
	}
	for (size_t i = 0; i < p.length(); i++)
	{
		if (!std::isdigit(p[i]))
		{
			std::cout << "Error. Phone Number is NaN." << std::endl;
			return (false);
		}
	}
    return (true);
}

bool	is_onlyspace(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return (false);
	}
	return (true);
}

bool	invalid_fields(std::string f, std::string l, std::string n, std::string s)
{
	if (f.empty() || l.empty() || n.empty() || s.empty())
	{
		std::cout << "Error. Empty field(s)." << std::endl;
		return (true);
	}
	if (is_onlyspace(f) || is_onlyspace(l) || is_onlyspace(n) || is_onlyspace(s))
	{
		std::cout << "Error. Field cannot be only spaces." << std::endl;
		return (true);
	}
	return (false);
}

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
	if (invalid_fields(f, l, n, s))
		return ;
	if (!is_validnum(p))
		return ;
	c.setContact(f, l, n, p, s);
	pb.addContact(c);
	return ;
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
