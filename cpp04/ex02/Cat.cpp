#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat assigment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void	Cat::setBrainIdea(int i, const std::string &idea)
{
	brain->setIdea(i, idea);
}

void	Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

std::string		Cat::getBrainIdea(int i) const
{
	return brain->getIdea(i);
}
