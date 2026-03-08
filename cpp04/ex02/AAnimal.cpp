#include "./AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "Abstract Animal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "Abstract Animal copy constructor called" << std::endl;
	this->type = other.type;
}

AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Abstract Animal assigment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Abstract Animal destructor called" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}
