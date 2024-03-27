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
	Zombie& operator=(const Zombie& other);
	void announce();
	void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
