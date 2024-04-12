#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
	Animal *base = new Animal();
	Animal *a = new Cat();
	Animal *b = new Dog();
	WrongAnimal *fakeCat = new WrongCat();

	std::cout << base->getType() << std::endl;
	std::cout << a->getType() << std::endl;
	std::cout << b->getType() << std::endl;
	std::cout << fakeCat->getType() << std::endl;

	base->makeSound();
	a->makeSound();
	b->makeSound();
	fakeCat->makeSound();

	delete base;
	delete a;
	delete b;
	delete fakeCat;

	return 0;
}
