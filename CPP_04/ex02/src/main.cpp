#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << std::endl << std::endl << "\t ABSTRACT CLASS " << std::endl << std::endl;
	std::cout << "- Making sure Animal can't be instanciated -" << std::endl << std::endl;

	{
		std::cout << "Because of the makeSound() = 0 in Animal.hpp,";
		std::cout << " Animal is an abstract class." << std::endl;
		std::cout << "I cannot instanticate it without declaring a derived,";
		std::cout << " non abstract class." << std::endl;
		std::cout << "To test this, uncomment the code below :" << std::endl;
		// Animal meta; // does not compile
		Dog	matt; // compiles, create an Animal, then make it a dog

	}

	std::cout << std::endl << std::endl << "\t ANIMAL ARRAY" << std::endl << std::endl;
	std::cout << "- Animal Array can still be declared and used to delete different animals -" << std::endl << std::endl;

	int		arraySize = 4;
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


	return 0;
}
