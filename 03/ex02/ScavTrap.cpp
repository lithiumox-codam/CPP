#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " have enterred in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
	std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage
			  << " points of damage!" << std::endl;
}
