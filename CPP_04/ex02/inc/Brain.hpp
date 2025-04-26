#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

# include <string>
# include <iostream>

class Brain {

	public:

		//----------------- CONSTRUCTORS ---------------------//
						Brain();

		//----------------- DESTRUCTOR -----------------------//
						~Brain();

		//----------------- COPY CONSTRUCTORS ----------------//
						Brain( const Brain& original );

		//----------------- COPY ASSIGNEMENT -----------------//
		Brain&			operator=( const Brain& original );

		std::string	ideas[100];

};


#endif
