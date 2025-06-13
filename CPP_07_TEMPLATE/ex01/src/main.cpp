#ifndef TEST

#include <iostream>
#include <string>
#include "iter.hpp"

#define LEN 5

void	printInt(int num)
{
	std::cout << "Int is " << num << std::endl;
}

void	printFloat(float num)
{
	std::cout << "Float is " << num << std::endl;
}

void	printChar(char character)
{
	std::cout << "Char is " << character << std::endl;
}

int	main()
{
	std::cout << "INTEGER ARRAY TEST" << std::endl;
	std::cout << "Let's initialize an int array." << std::endl;
	int	arrayOfInt[LEN] = {4, 3, 2, 1, 0};

	std::cout << "We can use the iter function with the array address,";
	std::cout << " length and a function designed for integers:" << std::endl;
	iter(arrayOfInt, LEN, printInt);

	std::cout << "But also another templete based function if we specify";
	std::cout << " the type: " << std::endl;
	iter(arrayOfInt, LEN, printAnyElem<int>);

	std::cout << "And even combine these template based functions ";
	std::cout << "by first incrementing and then printing." << std::endl;
	iter(arrayOfInt, LEN, incrementAnyElem<int>);
	iter(arrayOfInt, LEN, printAnyElem<int>);
	std::cout << std::endl;


	std::cout << "FLOAT ARRAY TEST" << std::endl;
	std::cout << "Let's initialize a float array." << std::endl;
	float	arrayOfFloat[LEN] = {4.0f, 3.5f, 2.3f, 1.0f, 0.4f};

	std::cout << std::endl << "We can use the iter function with the array address,";
	std::cout << " length and a function designed for integers:" << std::endl;
	iter(arrayOfFloat, LEN, printFloat);

	std::cout << "But also another templete based function if we specify";
	std::cout << " the type: " << std::endl;
	iter(arrayOfFloat, LEN, printAnyElem<float>);

	std::cout << "And even combine these template based functions ";
	std::cout << "by first incrementing and then printing." << std::endl;
	iter(arrayOfFloat, LEN, incrementAnyElem<float>);
	iter(arrayOfFloat, LEN, printAnyElem<float>);


	std::cout  << std::endl << "CHAR TEST" << std::endl;
	std::cout << "Let's initialize a string: ";
	std::string str = "Hello and goodbye";
	std::cout << str << std::endl;

	std::cout << "We can use the iter function with the array address,";
	std::cout << " length and a function designed for string:" << std::endl;
	iter(str, str.length(), printChar);

	std::cout << "But also another templete based function if we specify";
	std::cout << " the type: " << std::endl;
	iter(str, str.length(), printAnyElem<char>);

	std::cout << "And even combine these template based functions ";
	std::cout << "by first incrementing and then printing." << std::endl;
	iter(&str[0], str.length(), incrementAnyElem<char>);
	iter(str, str.length(), printAnyElem<char>);

	return 0;
}

#endif

#ifdef TEST

#include <iostream>
#include <string>
#include "iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}

#endif
