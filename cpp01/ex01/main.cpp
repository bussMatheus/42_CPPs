#include "./Zombie.hpp"

int	main(void)
{
	int	N;
	int	i;

	N = 0;
	i = 0;
	Zombie* horde = zombieHorde(N, "jeff");
	if (!horde)
		return 1;
	while (i < N)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return (0);
}