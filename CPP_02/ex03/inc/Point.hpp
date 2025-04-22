#ifndef POINT_CLASS_H
# define POINT_CLASS_H

# include "Fixed.hpp"

class Point {

public:

	//----------------- CONSTRUCTORS ---------------------//
					Point();
					Point( float const a, float const b );
					Point( Fixed newx, Fixed newy );

	//----------------- COPY CONSTRUCTORS ----------------//
					Point( const Point& original );

	//----------------- DESTRUCTOR -----------------------//
					~Point();

	//----------------- COPY ASSIGNEMENT -----------------//
	Point&			operator=( const Point& original );

	//----------------- MEMBER FUNCTION ------------------//
	Fixed const			getx() const ;
	Fixed const			gety() const ;

private:

	Fixed const		x;
	Fixed const		y;

};

#endif
