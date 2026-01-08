#include "./Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point	&Point::operator=(const Point &other){
	//Cannot do anything as _x && _y are const
	(void)other;
	return (*this);
}

Point::~Point(void) {}

Fixed	Point::getX() const { return _x; }
Fixed	Point::getY() const { return _y; }