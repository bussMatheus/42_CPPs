#include "./Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat a("Jeff", 2);
		std::cout << a << std::endl;

		a.incrementGrade();
		std::cout << a << std::endl;

		a.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	std::cout << "--------" << std::endl;

	try
	{
		Bureaucrat b("Bella", 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught: " << e.what() << '\n';
	}
	try
	{
		Bureaucrat c("C", 150);

		c.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught: " << e.what() << '\n';
	}

	return (0);
}