#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat constructor made" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor made" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assigment operator called!" << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout	<< _name << " couldn't sign " << form.getName() 
					<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout	<< _name << " couldn't execute " << form.getName() 
					<< " because " << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
