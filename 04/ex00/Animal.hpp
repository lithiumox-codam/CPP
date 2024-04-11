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
	  virtual std::string getType(void);
	  virtual void makeSound(void);
}
