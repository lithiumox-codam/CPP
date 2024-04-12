#include "Animal.hpp"

#include <iostream>

Animal::Animal() {
	std::cout << "Animal constructor called" << std::endl;
	this->type = "Animal";
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = other.type;
	return *this;
}

std::string Animal::getType(void) const { return this->type; }

void Animal::setType(std::string type) { this->type = type; }

void Animal::makeSound() { std::cout << "*Generic animal sound*" << std::endl; }
