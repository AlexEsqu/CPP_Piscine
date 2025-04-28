#include "Point.hpp"
#include "BSP.hpp"

int	main( void ) {

	const Point	p(2, 1);
	const Point	a(5, 5);
	const Point	b(0, 0);
	const Point	c(10, 0);

	std::cout << "Is Point (" << p.getx() << ";" << p.gety() << ") in triangle ";
	std::cout << "A (" << a.getx() << "," << a.gety() << "), ";
	std::cout << "B (" << b.getx() << "," << b.gety() << "), ";
	std::cout << "C (" << c.getx() << "," << c.gety() << ") ? ";

	std::cout << std::boolalpha << bsp(a, b, c, p) << std::endl;

	return 0;
}
