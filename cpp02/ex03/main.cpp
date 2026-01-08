#include "./Fixed.hpp"
#include "./Point.hpp"

static Fixed	cross(Point const &a, Point const &b, Point const &p){
	return (b.getX() - a.getX()) * (p.getY() - a.getY())
			- (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed ab = cross(a, b, point);
	Fixed bc = cross(b, c, point);
	Fixed ca = cross(c, a, point);

	if (ab == Fixed(0) || bc == Fixed(0) || ca == Fixed(0))
		return (false);

	bool has_neg = (ab < Fixed(0)) || (bc < Fixed(0)) || (ca < Fixed(0));
	bool has_pos = (ab > Fixed(0)) || (bc > Fixed(0)) || (ca > Fixed(0));

	if (has_neg && has_pos)
		return (false);
	return (true);
}

int	main(void){
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(0, 10);

	Point	inside(2, 2);
	Point	outside(12, 12);
	Point	edge(5, 0);
	Point	inPoint(0, 0);

	std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
	std::cout << "Edge: " << bsp(a, b, c, edge) << std::endl;
	std::cout << "In Point: " << bsp(a, b, c, inPoint) << std::endl;
	return (0);
}