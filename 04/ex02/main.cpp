#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMAL_COUNT 100

int main(void) {
	Animal* pets[100];

	for (int i = 0; i < ANIMAL_COUNT; i++) {
		if (i % 2 == 0) {
			pets[i] = new Dog();
		} else {
			pets[i] = new Cat();
		}
	}

	for (int i = 0; i < ANIMAL_COUNT; i++) {
		pets[i]->makeSound();
	}

	for (int i = 0; i < ANIMAL_COUNT; i++) {
		delete pets[i];
	}

	return 0;
}
