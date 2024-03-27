#include "Zombie.hpp"

#include <iostream>

/**
 * @brief Announces the zombie to the world
 */
void Zombie::announce(void) { std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl; }

/**
 * @brief Sets the name of the zombie
 * @param name The name of the zombie
 */
void Zombie::setName(std::string name) { this->name = name; }

/**
 * @brief Constructor for the zombie class
 * @return The name of the zombie (Mees by default)
 */
Zombie::Zombie() { this->name = "Mees"; }

/**
 * @brief Destructor for the zombie class that announces the death of the zombie
 */
Zombie::~Zombie(void) { std::cout << this->name << " is dead" << std::endl; }

Zombie& Zombie::operator=(const Zombie& zombie) {
	this->name = zombie.name;
	return *this;
}
