#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal() {
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
};

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
};

Cat::Cat(const Cat &other) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	if (this != &other) {
		brain = new Brain(*other.brain);
		type = other.type;
	}
};

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other) {
		delete brain;
		brain = new Brain(*other.brain);
		type = other.type;
	}
	return *this;
};

void Cat::makeSound() { std::cout << "Meow Meow" << std::endl; };
