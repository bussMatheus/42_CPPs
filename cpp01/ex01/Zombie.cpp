#include "./Zombie.hpp"

Zombie::Zombie(void) : _name("Unamed")
{}

Zombie::Zombie(std::string name) : _name(name)
{}

Zombie::~Zombie(void)
{
	std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _name << ": Btaiiiiiiinnnzzzz..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}
