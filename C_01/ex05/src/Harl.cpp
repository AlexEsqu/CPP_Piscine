#include "Harl.hpp"

void	complain( std::string level ) {

}

void	debug( void ) {
	std::cout << "I love having extra bacon for my7XL-double-cheese-triple";
	std::cout << "-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl;
}

void	info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You ";
	std::cout << "didn’t put enough bacon in my burger! If you did, I wouldn’t";
	std::cout << " be asking for more!" << std::endl;
}

void	warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve ";
	std::cout << "been coming for years, whereas you started working here last";
	std::cout << " month." << std::endl;
}

void	error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}
