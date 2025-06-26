#ifndef CLASS_CAT_HPP
# define CLASS_CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {

	public:

		//----------------- CONSTRUCTORS ---------------------//
						Cat();

		//----------------- DESTRUCTOR -----------------------//
						~Cat();

		//----------------- COPY CONSTRUCTORS ----------------//
						Cat( const Cat& original );

		//----------------- COPY ASSIGNEMENT -----------------//
		Cat&			operator=( const Cat& original );

		//----------------- MEMBER FUNCTIONS -----------------//
		void			makeSound() const;
		std::string		getType() const;
		void			addIdea( std::string idea, unsigned int index );
		std::string		getIdea( unsigned int index );


	private:

		Brain*			_brain;

	};


#endif
