#ifndef CLASS_ANIMAL_H
# define CLASS_ANIMAL_H

# include <string>
# include <iostream>

class Animal {

	public:

		//----------------- CONSTRUCTORS ---------------------//
						Animal();

		//----------------- DESTRUCTOR -----------------------//
		virtual			~Animal();

		//----------------- COPY CONSTRUCTORS ----------------//
						Animal( const Animal& original );

		//----------------- COPY ASSIGNEMENT -----------------//
		Animal&			operator=( const Animal& original );

		//----------------- MEMBER FUNCTIONS -----------------//
		virtual void	makeSound() const;
		std::string		getType() const;
		void			setType( std::string new_type );


	protected:

		std::string		type;



	private:


};


#endif
