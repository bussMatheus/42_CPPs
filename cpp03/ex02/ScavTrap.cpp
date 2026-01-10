#include "./ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap")
{
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;

	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;

	std::cout << "ScavTrap named constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Assigment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hitPts <= 0 || _energyPts <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack" << std::endl;
		return ;
	}
	_energyPts--;
	std::cout	<< "ScavTrap " << _name
				<< " ferociously attacks "
				<< target << ", causing "
				<< _attackDmg << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout	<< "ScavTrap " << _name
				<< " is now in Gate keeper mode!" << std::endl;
}