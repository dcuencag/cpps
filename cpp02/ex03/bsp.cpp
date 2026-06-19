#include "Point.hpp"

static Fixed	area(Point const a, Point const b, Point const c)
{
	Fixed	result;

	result = (a.getX() * (b.getY() - c.getY()))
		+ (b.getX() * (c.getY() - a.getY()))
		+ (c.getX() * (a.getY() - b.getY()));
	if (result < Fixed(0))
		result = result * Fixed(-1);
	return (result / Fixed(2));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	total;
	Fixed	s1;
	Fixed	s2;
	Fixed	s3;

	total = area(a, b, c);
	s1 = area(point, b, c);
	s2 = area(a, point, c);
	s3 = area(a, b, point);
	if (s1 == Fixed(0) || s2 == Fixed(0) || s3 == Fixed(0))
		return (false);
	return ((s1 + s2 + s3) == total);
}
