#include "Zombie.hpp"

#include <iostream>

void Zombie::announce() {
	std::cout << this->name << " BraiiiiiiinnnzzzZ..."
			  << "\n";
}

Zombie::Zombie(std::string name) { this->name = name; }

Zombie::~Zombie() {
	std::cout << this->name << " is dead"
			  << "\n";
}
