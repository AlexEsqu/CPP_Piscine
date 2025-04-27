#ifndef CLASS_MATERIASOURCE_H
# define CLASS_MATERIASOURCE_H

# include <string>
# include "A_Materia.hpp"
# include "I_MateriaSource.hpp"


class MateriaSource: virtual public IMateriaSource
{
	private:

		AMateria*			_learned[4];

	public:

		//----------------- CONSTRUCTORS ---------------------//
							MateriaSource();

		//----------------- DESTRUCTOR -----------------------//
							~MateriaSource();

		//----------------- COPY CONSTRUCTORS ----------------//
							MateriaSource( const MateriaSource& original );

		//----------------- COPY ASSIGNEMENT -----------------//
		MateriaSource&		operator=( const MateriaSource& original );

		//----------------- MEMBER FUNCTION ------------------//
		void				learnMateria( AMateria* m );
		AMateria*			createMateria( std::string const & type );

};



#endif

