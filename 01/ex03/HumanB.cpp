#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB() {}

void HumanB::attack() {
	if (weapon == nullptr)
		std::cout << name << " attacks with his bare hands\n";
	else
		std::cout << name << " attacks with his " << (*this->weapon).getType() << "\n";
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }
