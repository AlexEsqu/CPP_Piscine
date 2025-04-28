#ifndef CLASS_CHARACTER_H
# define CLASS_CHARACTER_H

# include <string>
# include "A_Materia.hpp"
# include "I_Character.hpp"

struct Node
{
	AMateria*	materia;
	Node*		next;
};

class Character: virtual public ICharacter
{

	private:

		std::string			_name;
		AMateria*			_inventory[4];
		Node*				_drop_list; // list of dropped materia to free

	public:
		//----------------- CONSTRUCTORS ---------------------//
							Character( const std::string& name );

		//----------------- DESTRUCTOR -----------------------//
							~Character();

		//----------------- COPY CONSTRUCTORS ----------------//
							Character( const Character& original );

		//----------------- COPY ASSIGNEMENT -----------------//
		Character&			operator=( const Character& original );

		//----------------- MEMBER FUNCTIONS -----------------//
		const std::string&	getName() const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );

		void				drop( int idx );

};

#endif
