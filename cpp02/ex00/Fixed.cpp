#include "./Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & instance)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = instance;
}

Fixed &Fixed::operator=(const Fixed & instance)
{
	std::cout << "Copy assigment opertator called" << std::endl;
	if (this != &instance)
		this->_rawBits = instance.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

