#include <iostream>

#include "Zombie.hpp"

#define AMOUNT 10

int main() {
	Zombie *horde = zombieHorde(AMOUNT, "Kees");
	if (horde == NULL) {
		std::cout << "malloc failed!" << std::endl;
		return 1;
	}

	std::cout << "Amount of zombies: " << AMOUNT << std::endl << std::endl;
	for (int i = 0; i < AMOUNT; i++) horde[i].announce();

	delete[] horde;
	return 0;
}
