#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
public:
	AForm();
	AForm(const std::string name, int gradeToSign, int gradeToExeccute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	//getters
	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void		beSigned(const Bureaucrat &b);
	void		execute(const Bureaucrat &b) const;

	virtual void	action() const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif