#pragma once

#include <string>

class Animal {
   protected:
	std::string type;

   public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);
	std::string getType(void) const;
	void setType(std::string type);
	virtual void makeSound(void) = 0;
};
