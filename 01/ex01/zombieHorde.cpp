#include "Zombie.hpp"

/**
 * @brief Creates a horde of zombies in the heap in a single allocation.
 *
 * @param N The number of zombies to create.
 * @param name The name of the zombies.
 */
Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return horde;
}
