#include "./FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

void FragTrap::highFivesGuys(void) {
	if (this->isDead()) return;
	std::cout << "FragTrap " << this->_name << " is requesting a high five" << std::endl;
}
