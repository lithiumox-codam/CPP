#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal() {
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
};

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; };

Cat::Cat(const Cat &other) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
};

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat assignation operator called" << std::endl;
	type = other.type;
	return *this;
};

void Cat::makeSound() { std::cout << "Meow Meow" << std::endl; };
