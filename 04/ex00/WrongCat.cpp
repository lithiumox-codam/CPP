#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const& src) : WrongAnimal(src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat& WrongCat::operator=(WrongCat const& other) {
	if (this != &other) WrongAnimal::operator=(other);
	std::cout << "WrongCat assignation operator called" << std::endl;
	return *this;
}

void WrongCat::makeSound() const { std::cout << "Wrong Meow" << std::endl; }
