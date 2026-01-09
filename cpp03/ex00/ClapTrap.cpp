#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Unamed"),
		_hitPts(10), _energyPts(10), _attackDmg(0) {}

ClapTrap::ClapTrap(std::string name) : _name(name),
		_hitPts(10), _energyPts(10), _attackDmg(0) {}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	(*this) = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPts = other._hitPts;
		_energyPts = other._energyPts;
		_attackDmg = other._attackDmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void) {}


//Methods
void	ClapTrap::attack(const std::string &target)
{
	if (_hitPts <= 0 || _energyPts <= 0)
	{
		std::cout << "ClapTrap " << _name << "can't attack\n";
		return ;
	}
	_energyPts--;
	std::cout	<< "ClapTrap " << _name
				<< " attacks " << target
				<< ", causing "<< _attackDmg
				<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitPts -= amount;
	if (_hitPts < 0)
		_hitPts = 0;

	std::cout	<< "ClapTrap " << _name
				<< " takes " << amount
				<< " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPts <= 0 || _energyPts <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair\n";
		return ;
	}
	_energyPts--;
	_hitPts += amount;

	std::cout	<< "ClapTrap " << _name
				<< " repairs itself for "
				<< amount << " hit points!" << std::endl;
}