#include "Zombie.hpp"

/**
 * @brief Construct a new Zombie:: Zombie object and announce directly
 * This places the zombie object on the stack there is no need to delete it
 * @param name
 */
void randomChump(std::string name) {
	Zombie zombie(name);
	zombie.announce();
}
