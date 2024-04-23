#include "Zombie.hpp"

/**
 * @brief Construct a new Zombie:: Zombie object
 * @warning This allocates memory for the zombie object
 * @param name
 */
Zombie* newZombie(std::string name) {
	Zombie* zombie = new Zombie(name);
	return (zombie);
}
