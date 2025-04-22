#include "Point.hpp"

//----------------- CONSTRUCTORS ---------------------//

		Point::Point(): x(Fixed(0)), y(Fixed(0)) {
	// std::cout << "Default constructor called" << std::endl;
}

		Point::Point( Fixed newx, Fixed newy ): x(newx), y(newy) {
	// std::cout << "Fixed constructor called" << std::endl;
}

		Point::Point( float const newx, float const newy ): x(Fixed(newx)), y(Fixed(newy)) {
	// std::cout << "Float constructor called" << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

		Point::Point( const Point& original ): x(original.x), y(original.y) {
	// std::cout << "Copy constructor called" << std::endl;
}

//----------------- DESTRUCTOR -----------------------//

		Point::~Point() {
	// std::cout << "Default destructor called" << std::endl;
}

//----------------- COPY ASSIGNEMENT -----------------//

Point&	Point::operator=( const Point& original ) {

	// std::cout << "Copy assignement operator called" << std::endl;
	if (this != &original) {
		(Fixed) this->x = original.x;
		(Fixed) this->y = original.y;
	}
	return *this;
}

//----------------- MEMBER FUNCTION ------------------//

Fixed const	Point::getx() const {
	return x;
}

Fixed const	Point::gety() const {
	return y;
}
