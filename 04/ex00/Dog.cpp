#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal() {
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(const Dog &dog) : Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
	std::cout << "Dog assignation operator called" << std::endl;
	type = dog.type;
	return *this;
}

void Dog::makeSound() { std::cout << "Woof Woof" << std::endl; }
