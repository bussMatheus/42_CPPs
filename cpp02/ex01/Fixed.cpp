#include "./Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

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
	return (*this);
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
	return (float)_rawBits / (1 << _fractionalBits);
}

int		Fixed::toInt(void) const
{
	return _rawBits >> _fractionalBits;
}

//Overload of insertion operator (<<)
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}