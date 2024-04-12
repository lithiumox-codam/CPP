#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal() {
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &dog) : Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	if (this != &dog) {
		type = dog.type;
		brain = new Brain(*dog.brain);
	}
}

Dog &Dog::operator=(const Dog &dog) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &dog) {
		type = dog.type;
		delete brain;
		brain = new Brain(*dog.brain);
	}
	return *this;
}

void Dog::makeSound() { std::cout << "Woof Woof" << std::endl; }
