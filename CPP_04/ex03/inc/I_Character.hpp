#ifndef CLASS_ICHARACTER_H
# define CLASS_ICHARACTER_H

# include <string>
# include "Readablity.hpp"
# include "A_Materia.hpp"

class AMateria;

class ICharacter
{

	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

};

#endif
