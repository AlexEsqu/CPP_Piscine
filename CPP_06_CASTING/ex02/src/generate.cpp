#include "generate.hpp"

static int	randomFrom0ToMax(int max)
{
	static bool	isSeeded = false;
	int			randomNum;

	if (!isSeeded) {
		std::srand(std::time(0));
		isSeeded = true;
	}

	randomNum = std::rand();

	if (randomNum > max)
		randomNum = randomNum % max;

	return (randomNum);
}

Base*	generate(void)
{
	int random = randomFrom0ToMax(3);

	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "WTF ???" << std::endl;
}

void	identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) {
		std::cout << "WTF ???" << std::endl;
	}
}
