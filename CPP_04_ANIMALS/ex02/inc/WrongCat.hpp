#ifndef CLASS_WRONG_CAT_HPP
# define CLASS_WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {

	public:

		//----------------- CONSTRUCTORS ---------------------//
						WrongCat();

		//----------------- DESTRUCTOR -----------------------//
						~WrongCat();

		//----------------- COPY CONSTRUCTORS ----------------//
						WrongCat( const WrongCat& original );

		//----------------- COPY ASSIGNEMENT -----------------//
		WrongCat&			operator=( const WrongCat& original );

		//----------------- MEMBER FUNCTIONS -----------------//
		void			makeSound() const;
		std::string		getType() const;


	private:


	};


#endif
