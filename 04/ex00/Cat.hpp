#pragma once

#include "Animal.hpp"

class Cat : public Animal {
   public:
	Cat();
	~Cat() override;
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	void makeSound(void) override;
};
