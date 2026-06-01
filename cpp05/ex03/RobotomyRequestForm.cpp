#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("Unamed")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void	RobotomyRequestForm::action() const
{
	std::cout << "** drilling noises **" << std::endl;

	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomization failed on " << _target << std::endl;
}
