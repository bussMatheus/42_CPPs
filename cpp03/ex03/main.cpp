#include "./ClapTrap.hpp"
#include "./DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a("Lucy");

	a.attack("enemy");
	a.takeDamage(30);
	a.beRepaired(20);
	a.highFivesGuys();
	a.guardGate();
	a.whoAmI();

	return 0;
}