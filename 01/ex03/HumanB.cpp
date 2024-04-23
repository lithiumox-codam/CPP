#include "HumanB.hpp"

#include <iostream>

#include "Weapon.hpp"

HumanB::HumanB() : name("default"), weapon(nullptr) {}

HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {}

HumanB::~HumanB() {}

HumanB &HumanB::operator=(const HumanB &other) {
	if (this == &other) return *this;
	this->name = other.name;
	this->weapon = other.weapon;
	return *this;
}

void HumanB::attack() {
	if (this->weapon == nullptr)
		std::cout << name << " attacks with his bare hands\n";
	else
		std::cout << name << " attacks with his " << (*this->weapon).getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }
