#include "./Zombie.hpp"

int main(void)
{
	Zombie* z = newZombie("Bro (He just woke up)");
	z->announce();
	delete z;

	randomChump("StackedBro");
	return 0;
}
