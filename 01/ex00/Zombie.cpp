#include "Zombie.hpp"

#include <iostream>

/**
 * @brief Announces the zombie to the world
 */
void Zombie::announce() { std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl; }

/**
 * @brief Construct a new Zombie:: Zombie object
 *
 * @param name The name of the zombie
 */
Zombie::Zombie(std::string name) { this->name = name; }

/**
 * @brief Destructor for the Zombie:: Zombie object
 */
Zombie::~Zombie() { std::cout << this->name << " is dead" << std::endl; }

/**
 * @brief Set the name of the zombie
 *
 * @param name The name of the zombie
 */
Zombie::Zombie() { this->name = "Zombie"; }

Zombie& Zombie::operator=(const Zombie& zombie) {
	this->name = zombie.name;
	return *this;
}
