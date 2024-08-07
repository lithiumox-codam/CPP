#include "ClapTrap.hpp"

#include <iostream>

bool ClapTrap::isDead() const { return _hitPoints <= 0; }

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	_name = "ClapTrap";
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	_name = name;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
	_name = clapTrap._name;
	_hitPoints = clapTrap._hitPoints;
	_energyPoints = clapTrap._energyPoints;
	_attackDamage = clapTrap._attackDamage;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap) {
	_name = clapTrap._name;
	_hitPoints = clapTrap._hitPoints;
	_energyPoints = clapTrap._energyPoints;
	_attackDamage = clapTrap._attackDamage;
	std::cout << "ClapTrap assignation operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap destructor called" << std::endl; }

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->isDead()) return;
	if (amount > _hitPoints) {
		_hitPoints = 0;
		std::cout << _name << " died" << std::endl;
		return;
	}
	_hitPoints -= amount;
	std::cout << _name << " took " << amount << " damage" << std::endl;
	if (_hitPoints == 0) {
		std::cout << _name << " died" << std::endl;
	}
}

void ClapTrap::attack(const std::string& target) {
	if (this->isDead()) return;
	if (this->_energyPoints <= 0) {
		std::cout << "Not enough energy to attack" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!"
			  << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->isDead()) return;
	if (_hitPoints == 100) {
		std::cout << _name << " is already at full health" << std::endl;
		return;
	} else if (_energyPoints <= 0) {
		std::cout << "Not enough energy to repair" << std::endl;
		return;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << _name << " was repaired for " << amount << " hit points" << std::endl;
}
