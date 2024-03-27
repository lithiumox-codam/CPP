#pragma once
#ifndef ZombieHorde_HPP
#define ZombieHorde_HPP

#include <string>

class Zombie {
   private:
	std::string name;

   public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	Zombie &operator=(Zombie const &rhs);
	void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
