#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap x("Geert");
	ScavTrap y("Mees");
	FragTrap z("Jelle");

	for (int i = 0; i < 50; i++) {
		x.attack("a tree");
		x.takeDamage(10);
		x.beRepaired(1);
	}
	for (int i = 0; i < 50; i++) {
		y.attack("a tree");
		y.takeDamage(10);
		y.beRepaired(1);
	}
	for (int i = 0; i < 50; i++) {
		z.attack("a tree");
		z.takeDamage(10);
		z.beRepaired(1);
	}
	return 0;
}
