#include "./AForm.hpp"

AForm::AForm() : _name("unamed"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExeccute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExeccute)
{
	if (gradeToSign < 1 || gradeToExeccute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExeccute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool		AForm::getIsSigned() const { return _isSigned; }
int			AForm::getGradeToSign() const { return _gradeToSign; }
int			AForm::getGradeToExecute() const { return _gradeToExecute; }

void		AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void		AForm::execute(const Bureaucrat &b) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (b.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	action();
}

//Exceptions

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form: Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os	<< f.getName() << ", signed: " << f.getIsSigned()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to exec: " << f.getGradeToExecute();
	return os;
}
