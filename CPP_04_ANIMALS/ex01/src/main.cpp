#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << std::endl << std::endl << "\t MEMORY ALLOCATION" << std::endl << std::endl;
	std::cout << "- Making sure Brains don't leak -" << std::endl << std::endl;

	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;
	}

	std::cout << std::endl << std::endl << "\t ANIMAL ARRAY" << std::endl << std::endl;
	std::cout << "- Using Animal Array to delete different animals -" << std::endl << std::endl;

	int		arraySize = 10;
	Animal*	animalArray[arraySize];

	std::cout << "Creating different animals using the array :" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		if (i % 2)
			animalArray[i] = new Dog();
		else
			animalArray[i] = new Cat();
	}
	std::cout << std::endl;

	std::cout << "Making use of them :" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		animalArray[i]->makeSound();
	}
	std::cout << std::endl;

	std::cout << "Destroying different animals using the array :" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		delete animalArray[i];
	}
	std::cout << std::endl;


	std::cout << std::endl << std::endl << "\t DEEP COPY" << std::endl << std::endl;
	std::cout << "- Ensure Ideas are correctly copied and assigned -" << std::endl << std::endl;

	{
		Dog	rex;

		rex.addIdea("Squirrel!!!", 10);

		Dog	rex_copy(rex);

		rex.addIdea("Beef!!!", 10);

		std::cout << rex_copy.getIdea(10) << std::endl;
		std::cout << rex.getIdea(10) << std::endl;
	}


	return 0;
}
