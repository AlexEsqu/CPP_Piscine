#ifndef CLASS_WRONG_ANIMAL_H
# define CLASS_WRONG_ANIMAL_H

# include <string>
# include <iostream>

class WrongAnimal {

	public:

		//----------------- CONSTRUCTORS ---------------------//
						WrongAnimal();

		//----------------- DESTRUCTOR -----------------------//
		virtual			~WrongAnimal();

		//----------------- COPY CONSTRUCTORS ----------------//
						WrongAnimal( const WrongAnimal& original );

		//----------------- COPY ASSIGNEMENT -----------------//
		WrongAnimal&	operator=( const WrongAnimal& original );

		//----------------- MEMBER FUNCTIONS -----------------//
		virtual void	makeSound() const;
		std::string		getType() const;
		void			setType( std::string new_type );


	protected:

		std::string		type;



	private:


};


#endif
