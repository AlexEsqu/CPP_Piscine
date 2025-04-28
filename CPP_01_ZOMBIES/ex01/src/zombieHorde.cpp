# include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {

	if (N <= 0)
		return (NULL);

	Zombie*	ZombieArrayStart = new Zombie[N];

	for (int i = 0; i < N; i++) {
		ZombieArrayStart[i].setZombieName(name);
	}
	return (ZombieArrayStart);
}
