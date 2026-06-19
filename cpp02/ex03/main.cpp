#include <iostream>
#include "Point.hpp"

static void	test(Point const a, Point const b, Point const c,
		Point const point, const char *name)
{
	std::cout << name << ": "
		<< (bsp(a, b, c, point) ? "inside" : "outside") << std::endl;
}

int	main(void)
{
	Point const a(0.0f, 0.0f);
	Point const b(10.0f, 0.0f);
	Point const c(0.0f, 10.0f);

	test(a, b, c, Point(2.0f, 2.0f), "inside point   ");
	test(a, b, c, Point(20.0f, 20.0f), "outside point  ");
	test(a, b, c, Point(0.0f, 0.0f), "on vertex      ");
	test(a, b, c, Point(5.0f, 0.0f), "on edge        ");
	test(a, b, c, Point(1.0f, 1.0f), "inside point 2 ");

	return (0);
}
