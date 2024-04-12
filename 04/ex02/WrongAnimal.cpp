#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal constructor called" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	type = wrongAnimal.type;
	return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() { std::cout << "WrongAnimal sound" << std::endl; }

std::ostream &operator<<(std::ostream &out, const WrongAnimal &wrongAnimal) {
	out << wrongAnimal.getType();
	return out;
}
