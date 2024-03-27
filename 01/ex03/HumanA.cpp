#include "HumanA.hpp"

#include <iostream>

#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {
	this->weapon = Weapon();
	this->name = "default";
}

HumanA &HumanA::operator=(const HumanA &other) {
	if (this == &other) return *this;
	this->name = other.name;
	this->weapon = other.weapon;
	return *this;
}

void HumanA::attack() { std::cout << this->name << " attacks with his " << this->weapon.getType() << "\n"; }
