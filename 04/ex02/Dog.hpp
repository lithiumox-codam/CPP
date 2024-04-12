#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
   private:
	Brain *brain;

   public:
	Dog();
	~Dog() override;
	Dog(const Dog &dog);
	Dog &operator=(const Dog &dog);
	void makeSound() override;
};
