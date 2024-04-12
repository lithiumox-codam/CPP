#pragma once

#include <string>

class WrongAnimal {
   protected:
	std::string type;

   public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &animal);
	WrongAnimal &operator=(const WrongAnimal &animal);
	std::string getType(void) const;
	void setType(std::string type);
	void makeSound(void);
};
