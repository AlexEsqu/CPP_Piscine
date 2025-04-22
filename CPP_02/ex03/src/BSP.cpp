#include "BSP.hpp"

Fixed	find_triangle_area( Point const a, Point const b, Point const c ) {
	Fixed	area;

	area = a.getx() * (b.gety() - c.gety())
		+ b.getx() * (c.gety() - a.gety())
		+ c.getx() * (a.gety() - b.gety());
	area = area / 2;

	if (area < 0)
		return (area * -1);

	return (area);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {

	Fixed	abc_triangle = find_triangle_area(a, b, c);

	if ( abc_triangle == 0)
		return (false);

	Fixed	pcb_triangle = find_triangle_area(point, c, b);

	Fixed	pac_triangle = find_triangle_area(point, a, c);

	Fixed	pab_triangle = find_triangle_area(point, a, b);

	return (abc_triangle == (pcb_triangle + pac_triangle + pab_triangle));
}
