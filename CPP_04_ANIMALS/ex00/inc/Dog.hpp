#ifndef CLASS_DOG_HPP
# define CLASS_DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {

	public:

		//----------------- CONSTRUCTORS ---------------------//
						Dog();

		//----------------- DESTRUCTOR -----------------------//
						~Dog();

		//----------------- COPY CONSTRUCTORS ----------------//
						Dog( const Dog& original );

		//----------------- COPY ASSIGNEMENT -----------------//
		Dog&			operator=( const Dog& original );

		//----------------- MEMBER FUNCTIONS -----------------//
		void			makeSound() const;
		std::string		getType() const;


	private:


	};


#endif
