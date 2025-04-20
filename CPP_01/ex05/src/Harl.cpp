#include "Harl.hpp"

		Harl::Harl( void ) {
	std::cout << "Harl has entered the burger joint." << std::endl;
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	actions[0] = &Harl::debug;
	actions[1] = &Harl::info;
	actions[2] = &Harl::warning;
	actions[3] = &Harl::error;
}

		Harl::~Harl( void ) {
	std::cout << "Harl has thankfully exited the burger joint. phewww...." << std::endl;
}

void	Harl::complain( std::string level ) {
	for (int i = 0; i < 4; i++) {
		if (level.compare(levels[i]) == 0) {
			(this->*actions[i])();
			return;
		}
	}
	std::cout << "The selected level " << level << " is invalid" << std::endl << std::endl;
}

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my7XL-double-cheese-triple";
	std::cout << "-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You ";
	std::cout << "didn’t put enough bacon in my burger! If you did, I wouldn’t";
	std::cout << " be asking for more!" << std::endl << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve ";
	std::cout << "been coming for years, whereas you started working here last";
	std::cout << " month." << std::endl << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl << std::endl;
}
