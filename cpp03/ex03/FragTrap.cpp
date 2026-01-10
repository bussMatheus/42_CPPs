#include "./FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(void)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assigment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FlagTrap::highFivesGuys(void)
{
	std::cout << "FragTrap requests a high five full of positive energy" << std::endl;
}