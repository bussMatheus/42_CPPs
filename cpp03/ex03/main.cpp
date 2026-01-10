#include "./ClapTrap.hpp"
#include "./FragTrap.hpp"

int	main(void)
{
	FragTrap a("Ezequiel");

	a.attack("enemy");
	a.takeDamage(30);
	a.beRepaired(20);
	a.highFivesGuys();

	return 0;
}