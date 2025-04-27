#ifndef CLASS_IMATERIASOURCE_H
# define CLASS_IMATERIASOURCE_H

# include <string>
# include "A_Materia.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
