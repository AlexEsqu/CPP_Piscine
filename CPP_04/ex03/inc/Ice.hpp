#ifndef CLASS_ICE_H
# define CLASS_ICE_H

# include <string>
# include "I_Character.hpp"
# include "A_Materia.hpp"

class Ice: virtual public AMateria
{
	protected:

		std::string			_type;

	public:

		//----------------- CONSTRUCTORS ---------------------//
							Ice();

		//----------------- DESTRUCTOR -----------------------//
							~Ice();

		//----------------- COPY CONSTRUCTORS ----------------//
							Ice( const Ice& original );

		//----------------- COPY ASSIGNEMENT -----------------//
		Ice&				operator=( const Ice& original );

		//----------------- MEMBER FUNCTIONS -----------------//
		const std::string&	getType() const;
		Ice*				clone() const;
		void				use(ICharacter& target);

};


#endif
