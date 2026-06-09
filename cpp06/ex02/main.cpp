#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int	main()
{
	Base	*ptr;

	std::srand(std::time(NULL));

	for (int i = 0; i < 5; i++)
	{
		std::cout << "------ TEST " << i + 1 << "-------" << std::endl;

		ptr = generate();

		std::cout << "identify(Base *): " << std::endl;
		identify(ptr);

		std::cout << "identify(Base &): " << std::endl;
		identify(*ptr);
		delete ptr;
		std::cout << std::endl;
	}
	return (0);	
}