#include "./Bureaucrat.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include <ctime>

int	main()
{
	std::srand(std::time(NULL));

	try
	{
		std::cout << " INVALID BUREAUCRAT " << std::endl;
		Bureaucrat wrong("Bad", 0);
	}
	catch(std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	
	Bureaucrat	pr("President", 1);
	Bureaucrat	rob("Rob", 50);
	Bureaucrat	joe("Joe", 150);

	ShrubberyCreationForm	shrub("home");
	RobotomyRequestForm		robot("Bender");
	PresidentialPardonForm	pardon("Bro");

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	std::cout << " UNSIGNED EXEC " << std::endl;
	pr.executeForm(shrub);

	std::cout << " SIGNING " << std::endl;
	joe.signForm(shrub);
	pr.signForm(shrub);
	pr.signForm(robot);
	pr.signForm(pardon);

	std::cout << " EXECUTION " << std::endl;
	rob.executeForm(shrub);
	pr.executeForm(robot);
	pr.executeForm(robot);
	pr.executeForm(robot);
	pr.executeForm(pardon);

	std::cout << " LOW GRADE EXECUTION " << std::endl;
	rob.executeForm(pardon);

	return (0);
}
