#include "ClapTrap.hpp"

int main(void) {
	ClapTrap x("Geert");

	for (int i = 0; i < 5; i++) {
		x.attack("a tree");
		x.takeDamage(10);
		x.beRepaired(500);
	}
	return 0;
}
