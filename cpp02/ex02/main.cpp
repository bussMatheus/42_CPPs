#include "./Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// Outer subject tests
	std::cout << std::endl << "=== Other tests ===" << std::endl;
	// Comparison tests
	Fixed x(10.5f);
	Fixed y(10.25f);

	std::cout << "\n--- Comparison tests ---" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "x > y  : " << (x > y) << std::endl;
	std::cout << "x < y  : " << (x < y) << std::endl;
	std::cout << "x >= y : " << (x >= y) << std::endl;
	std::cout << "x <= y : " << (x <= y) << std::endl;
	std::cout << "x == y : " << (x == y) << std::endl;
	std::cout << "x != y : " << (x != y) << std::endl;

	// Min Max tests
	std::cout << "\n--- Min / Max tests ---" << std::endl;
	Fixed m1(3.14f);
	Fixed m2(42.42f);

	std::cout << "min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
	std::cout << "max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;

	const Fixed cm1(1.5f);
	const Fixed cm2(1.25f);

	std::cout << "min(const) = " << Fixed::min(cm1, cm2) << std::endl;
	std::cout << "max(const) = " << Fixed::max(cm1, cm2) << std::endl;

	//
	std::cout << "\n--- Arithmetic tests ---" << std::endl;

	Fixed a1(5.5f);
	Fixed a2(2);

	std::cout << "a1 = " << a1 << std::endl;
	std::cout << "a2 = " << a2 << std::endl;

	std::cout << "a1 + a2 = " << (a1 + a2) << std::endl;
	std::cout << "a1 - a2 = " << (a1 - a2) << std::endl;
	std::cout << "a1 * a2 = " << (a1 * a2) << std::endl;
	std::cout << "a1 / a2 = " << (a1 / a2) << std::endl;

	return (0);
}