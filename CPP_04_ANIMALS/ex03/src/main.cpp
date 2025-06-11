#include "A_Materia.hpp"
#include "I_MateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "I_Character.hpp"
#include "Character.hpp"


int main()
{
	{
		std::cout << "Exercice Main" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	{
		std::cout << std::endl << "Equip more than 4 materias" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* hero = new Character("hero");
		// Equip 4 materias
		for (int i = 0; i < 4; ++i) {
			AMateria* m = src->createMateria(i % 2 == 0 ? "ice" : "cure");
			hero->equip(m);
		}
		// Try to equip a 5th materia (should not equip)
		AMateria* extra = src->createMateria("ice");
		hero->equip(extra);
		delete extra;

		std::cout << std::endl << "Use all slots" << std::endl;
		ICharacter* target = new Character("target");
		for (int i = 0; i < 4; ++i)
			hero->use(i, *target);

		std::cout  << std::endl << "Use empty slot" << std::endl;
		hero->use(4, *target);

		std::cout << std::endl << "Unequip and re-equip" << std::endl;
		hero->unequip(2);
		hero->use(2, *target);
		AMateria* newMat = src->createMateria("cure");
		hero->equip(newMat);
		hero->use(2, *target);

		std::cout << std::endl << "Deep copy character" << std::endl;
		Character* copyHero = new Character(*dynamic_cast<Character*>(hero));
		copyHero->use(0, *target);
		copyHero->use(2, *target);

		delete copyHero;
		delete target;
		delete hero;
		delete src;
	}

	{
		std::cout << std::endl << "Create unknown materia" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		AMateria* unknown = src->createMateria("fire");
		if (!unknown)
			std::cout << "Unknown materia returned nullptr as expected." << std::endl;
		delete src;
	}


	return 0;
}
