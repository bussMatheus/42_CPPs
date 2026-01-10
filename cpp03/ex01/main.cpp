#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("SC4Vson");

	a.attack("enemy");
	a.guardGate();

	return 0;
}