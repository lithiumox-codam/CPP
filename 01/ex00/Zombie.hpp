#pragma once
#ifndef ZombieHorde_HPP
#define ZombieHorde_HPP

#include <string>

class Zombie {
   private:
	std::string name;

   public:
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
