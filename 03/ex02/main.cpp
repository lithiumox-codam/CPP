#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap x("Geert");
	ScavTrap y("Mees");
	FragTrap z("Jelle");

	while (!x.isDead()) {
		x.attack("a tree");
		x.takeDamage(5);
		x.beRepaired(10);
	}
	while (!y.isDead()) {
		y.attack("a tree");
		y.takeDamage(10);
		y.beRepaired(1);
	}
	while (!z.isDead()) {
		z.attack("a tree");
		z.takeDamage(10);
		z.beRepaired(1);
	}
	return 0;
}
