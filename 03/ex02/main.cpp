#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap x("Geert");
	ScavTrap y("Mees");
	FragTrap z("Jizze");
	// FragTrap a = x;

	while (!x.isDead()) {
		x.attack("Mark");
		x.takeDamage(5);
		x.beRepaired(10);
	}
	while (!y.isDead()) {
		y.attack("Max");
		y.takeDamage(10);
		y.beRepaired(1);
	}
	while (!z.isDead()) {
		z.attack("Duko");
		z.takeDamage(10);
		z.beRepaired(1);
	}
	z.highFivesGuys();
	return 0;
}
