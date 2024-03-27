#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap x("Geert");
	ScavTrap y("Mees");

	for (int i = 0; i < 5; i++) {
		x.attack("a tree");
		x.takeDamage(10);
		x.beRepaired(500);
	}
	for (int i = 0; i < 5; i++) {
		y.attack("a tree");
		y.takeDamage(10);
		y.beRepaired(500);
	}
	return 0;
}
