#include "Zombie.hpp"

int main() {
	Zombie *Mees;
	Zombie *Kees;

	Mees = newZombie("Mees");
	Kees = newZombie("Kees");
	randomChump("Geert");

	Mees->announce();
	Kees->announce();

	delete Mees;
	delete Kees;
	return (0);
}
