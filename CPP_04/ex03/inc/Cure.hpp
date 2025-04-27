#ifndef CLASS_CURE_H
# define CLASS_CURE_H

# include <string>
# include "I_Character.hpp"
# include "A_Materia.hpp"

class Cure: virtual public AMateria
{
	protected:

		std::string			_type;

	public:

		//----------------- CONSTRUCTORS ---------------------//
							Cure();

		//----------------- DESTRUCTOR -----------------------//
							~Cure();

		//----------------- COPY CONSTRUCTORS ----------------//
							Cure( const Cure& original );

		//----------------- COPY ASSIGNEMENT -----------------//
		Cure&				operator=( const Cure& original );

		//----------------- MEMBER FUNCTIONS -----------------//
		const std::string&	getType() const;
		Cure*				clone() const;
		void				use(ICharacter& target);

};


#endif
