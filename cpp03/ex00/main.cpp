#include "./ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("CL4Pson");
	ClapTrap	b;

	a.attack("enemy");
	a.takeDamage(3);
	a.beRepaired(1);

	b = a;
	b.attack("another enemy");
	return (0);
}