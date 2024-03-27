#pragma once
#ifndef __HUMAN_A__
#define __HUMAN_A__

#include "Weapon.hpp"

class HumanA {
   private:
	std::string name;
	Weapon &weapon;

   public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	HumanA();
	HumanA &operator=(const HumanA &other);
	void attack();
};

#endif	// !__HUMAN_A__
