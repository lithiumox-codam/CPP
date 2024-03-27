#include "Weapon.hpp"

/**
 * @brief Weapon::Weapon Constructor
 * @param type Type of weapon
 */
Weapon::Weapon(std::string type) { this->type = type; }

Weapon::Weapon() { this->type = "default"; }

/**
 * @brief Weapon::~Weapon Destructor
 */
Weapon::~Weapon() { this->type = "default"; }

Weapon &Weapon::operator=(const Weapon &weapon) {
	this->type = weapon.type;
	return *this;
}

/**
 * @brief Weapon::setType Set the type of weapon
 * @param type Type of weapon
 */
void Weapon::setType(std::string type) { this->type = type; }

/**
 * @brief Weapon::getType Get the type of weapon
 * @return Type of weapon
 */
const std::string &Weapon::getType() { return this->type; }
