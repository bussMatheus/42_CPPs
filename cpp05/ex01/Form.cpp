#include "./Form.hpp"

Form::Form() : _name("unamed"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{}

Form::Form(const std::string name, int gradeToSign, int gradeToExeccute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExeccute)
{
	if (gradeToSign < 1 || gradeToExeccute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExeccute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const { return _name; }
bool		Form::getIsSigned() const { return _isSigned; }
int			Form::getGradeToSign() const { return _gradeToSign; }
int			Form::getGradeToExecute() const { return _gradeToExecute; }

void		Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

//Exceptions

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os	<< f.getName() << ", signed: " << f.getIsSigned()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to exec: " << f.getGradeToExecute();
	return os;
}