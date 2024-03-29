#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
	{
		Weapon club = Weapon("Assault Rifle");
		HumanA bob("Mees", club);
		bob.attack();
		club.setType("Butter knife");
		bob.attack();
	}
	{
		Weapon club = Weapon("Butter knife");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("Laser gun");
		jim.attack();
	}
	return 0;
}
