#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int	main()
{
	Bureaucrat pr("President", 1);
	Bureaucrat joe("Joe", 150);

	Form contract("Contract", 50, 20);

	std::cout << contract << std::endl;

	joe.signForm(contract);

	pr.signForm(contract);

	std::cout << contract << std::endl;
}