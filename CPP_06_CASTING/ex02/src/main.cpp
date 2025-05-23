#include "generate.hpp"
#define COUNT 10

int	main()
{
	std::cout << "Generating " << COUNT << " Base class: " << std::endl;
	Base*	arrayBase[COUNT];
	for (int i = 0; i < COUNT; i++) {
		arrayBase[i] = generate();
	}

	std::cout << "Identifying " << COUNT << " Base class through pointers: " << std::endl;
	for (int i = 0; i < COUNT; i++) {
		identify(arrayBase[i]);
	}

	std::cout << "Identifying " << COUNT << " Base class through reference: " << std::endl;
	for (int i = 0; i < COUNT; i++) {
		identify(*arrayBase[i]);
	}

	std::cout << "Deleting " << COUNT << " Base class" << std::endl;
	for (int i = 0; i < COUNT; i++) {
		delete arrayBase[i];
	}

	return (0);
}
