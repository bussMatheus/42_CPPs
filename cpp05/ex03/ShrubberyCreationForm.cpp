#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{} 

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::action() const
{
	std::ofstream file((_target + "_shrubbery").c_str());

	if (!file)
		throw std::runtime_error("could not create shrubbery file");

    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";
}