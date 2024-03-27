#include "HumanB.hpp"

#include <iostream>

#include "Weapon.hpp"

HumanB::HumanB() : name("default") {}

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB() {}

HumanB &HumanB::operator=(const HumanB &other) {
	if (this == &other) return *this;
	this->name = other.name;
	this->weapon = other.weapon;
	return *this;
}

void HumanB::attack() {
	if (weapon == nullptr)
		std::cout << name << " attacks with his bare hands\n";
	else
		std::cout << name << " attacks with his " << (*this->weapon).getType() << "\n";
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }
