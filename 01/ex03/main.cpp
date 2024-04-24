#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
	{
		std::cout << "\n{Type: HumanA Starting weapon: Assault Rifle}\n" << std::endl;
		Weapon club = Weapon("Assault Rifle");
		HumanA bob("Mees", club);
		bob.attack();
		club.setType("Butter knife");
		bob.attack();
	}
	{
		std::cout << "\n{Type: HumanB Starting weapon: Butter knife}\n" << std::endl;
		Weapon club = Weapon("Butter knife");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("Laser gun");
		jim.attack();
	}
	{
		std::cout << "\n{Type: HumanB Starting weapon: None}\n" << std::endl;
		HumanB kenny("Kenny");
		kenny.attack();
		Weapon nail = Weapon("Nail");
		kenny.setWeapon(nail);
		kenny.attack();
	}
	return 0;
}
