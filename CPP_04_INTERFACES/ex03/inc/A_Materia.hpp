#ifndef CLASS_AMATERIA_H
# define CLASS_AMATERIA_H

# include <string>
# include <iostream>
# include "Readablity.hpp"
# include "I_Character.hpp"

class ICharacter;

class AMateria
{
	protected:

		std::string			_type;

	public:

		//----------------- CONSTRUCTORS ---------------------//
							AMateria(const std::string& type);

		//----------------- DESTRUCTOR -----------------------//
		virtual				~AMateria();

		//----------------- COPY CONSTRUCTORS ----------------//
							AMateria( const AMateria& original );

		//----------------- COPY ASSIGNEMENT -----------------//
		AMateria&			operator=( const AMateria& original );

		//----------------- MEMBER FUNCTIONS -----------------//
		const std::string&	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

};


#endif
