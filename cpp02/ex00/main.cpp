#include "./Fixed.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

int	main(void)
{
	std::cout << BLUE << "=== Creating a ===" << RESET << std::endl;
	Fixed a;
	a.setRawBits(32);
	std::cout << BLUE << "\n=== Creating b from a (copy constructor)" << RESET << std::endl;
	Fixed b(a);

	std::cout << BLUE << "\n=== Creating c then assigning to b ===" << RESET << std::endl;
	Fixed c;
	c = b;

	std::cout << YELLOW << "\n=== Raw Bits Values ===" << RESET << std::endl;
	std::cout << GREEN << "a: " << RESET << a.getRawBits() << std::endl;
	std::cout << GREEN << "b: " << RESET << b.getRawBits() << std::endl;
	std::cout << GREEN << "c: " << RESET << c.getRawBits() << std::endl;
	return (0);
}