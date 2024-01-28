#pragma once
#ifndef ZombieHorde_HPP
#define ZombieHorde_HPP

#include <string>

class Zombie {
   private:
	std::string name;

   public:
	Zombie();
	~Zombie();
	void announce();
	void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
