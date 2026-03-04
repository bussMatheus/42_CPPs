#include "./Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog assigment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}
void	Dog::setBrainIdea(int i, const std::string &idea)
{
	brain->setIdea(i, idea);
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof!!" << std::endl;
}

std::string	Dog::getBrainIdea(int i) const
{
	return brain->getIdea(i);
}