#include <iostream>
#include <string>

int	main() {

	std::string		str = "'HI THIS IS BRAIN'";
	std::string*	p_str = &str;
	std::string		&r_str = str;

	std::cout << "Printing the address of the string : ";
	std::cout << &str << std::endl;

	std::cout << "Printing the address of the pointer on a string : ";
	std::cout << &p_str << std::endl;

	std::cout << "Printing the address of the reference on a string : ";
	std::cout << &r_str << std::endl;

	std::cout << std::endl;

	std::cout << "Printing the value of the string : ";
	std::cout << str << std::endl;

	std::cout << "Printing the value of the pointer on a string : ";
	std::cout << *p_str << std::endl;

	std::cout << "Printing the value of the reference on a string : ";
	std::cout << r_str << std::endl;

}



