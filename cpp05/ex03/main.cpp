#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(std::time(NULL));

	Intern		intern;
	Bureaucrat	boss("Boss", 1);

	AForm*	shrub = intern.makeForm("shrubbery creation", "home");
	AForm*	robot = intern.makeForm("robotomy request", "Bender");
	AForm*	pardon = intern.makeForm("presidential pardon", "Arthur");
	AForm*	invalid = intern.makeForm("MAke some coffe", "Joe");

	std::cout << std::endl;
	std::cout << "===== CREATED FORMS =====" << std::endl;;

	if (shrub)
		std::cout << *shrub << std::endl;
	if (robot)
		std::cout << *robot << std::endl;
	if (pardon)
		std::cout << *pardon << std::endl;
	if (invalid)
		std::cout << *invalid << std::endl;

	std::cout << std::endl;
	std::cout << "===== SIGN AND EXECUTE =====" << std::endl;

	if (shrub)
	{
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
	}
	if (robot)
	{
		boss.signForm(*robot);
		boss.executeForm(*robot);
	}
	if (pardon)
	{
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
	}

	delete shrub;
	delete robot;
	delete pardon;
	delete invalid;

	return 0;
}