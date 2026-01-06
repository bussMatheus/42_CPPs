#include "./Fixed.hpp"

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(f * (1 << _fractionalBits));
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

float	Fixed::toFloat(void) const
{
	return _rawBits >> _fractionalBits;
}
