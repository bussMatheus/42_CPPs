#include "./PhoneBook.hpp"
#include "./utils.hpp"

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
