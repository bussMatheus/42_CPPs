#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(std::string name);
	~Zombie();

	void	setName(std::string name);
	void	announce(void) const;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif