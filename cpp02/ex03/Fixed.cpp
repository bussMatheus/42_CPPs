#include "./Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	//std::cout << "Int constructor called" << std::endl;
	_rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
	//std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed & instance)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = instance;
}

Fixed &Fixed::operator=(const Fixed & instance)
{
	//std::cout << "Copy assigment opertator called" << std::endl;
	if (this != &instance)
		this->_rawBits = instance.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
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

//Overload for comparison operators
bool	Fixed::operator>(const Fixed &other) const { return _rawBits > other._rawBits; }
bool	Fixed::operator<(const Fixed &other) const { return _rawBits < other._rawBits; }
bool	Fixed::operator>=(const Fixed &other) const { return _rawBits >= other._rawBits; }
bool	Fixed::operator<=(const Fixed &other) const { return _rawBits <= other._rawBits; }
bool	Fixed::operator==(const Fixed &other) const { return _rawBits == other._rawBits; }
bool	Fixed::operator!=(const Fixed &other) const { return _rawBits != other._rawBits; }

//Overload for arithmetic operators
Fixed	Fixed::operator+(const Fixed &other) const { return Fixed(toFloat() + other.toFloat()); }
Fixed	Fixed::operator-(const Fixed &other) const { return Fixed(toFloat() - other.toFloat()); }
Fixed	Fixed::operator*(const Fixed &other) const { return Fixed(toFloat() * other.toFloat()); }
Fixed	Fixed::operator/(const Fixed &other) const { return Fixed(toFloat() / other.toFloat()); }

//Increment / Decrement
Fixed	&Fixed::operator++() { _rawBits++ ; return *this; }
Fixed	Fixed::operator++(int) { Fixed tmp(*this); _rawBits++ ; return tmp; }
Fixed	&Fixed::operator--() { _rawBits-- ; return *this; }
Fixed	Fixed::operator--(int) { Fixed tmp(*this); _rawBits-- ; return tmp; }

//Min / Max
Fixed		&Fixed::min(Fixed &a, Fixed &b) {return (a < b) ? a : b;}
Fixed const	&Fixed::min(const Fixed &a, const Fixed &b) {return (a < b) ? a : b;}
Fixed		&Fixed::max(Fixed &a, Fixed &b) {return (a > b) ? a : b;}
Fixed const	&Fixed::max(const Fixed &a, const Fixed &b) {return (a > b) ? a : b;}

//Overload of insertion operator (<<)
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}