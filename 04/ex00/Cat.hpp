#pragma once

#include "Animal.hpp"

class Cat: public Animal {
	public:
	  Cat();
	  void makesound() override;
}
