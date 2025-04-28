#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal* robot = new WrongAnimal();
	const WrongAnimal* roCat = new WrongCat();
	std::cout << robot->getType() << " " << std::endl;
	std::cout << roCat->getType() << " " << std::endl;
	robot->makeSound(); //will output the cat sound!
	roCat->makeSound();

	delete robot;
	delete roCat;

	return 0;
}
