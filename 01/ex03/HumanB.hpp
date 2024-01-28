#pragma once
#ifndef __HUMAN_B__
#define __HUMAN_B__

#include "Weapon.hpp"

class HumanB {
   private:
	std::string name;
	Weapon* weapon;

   public:
	explicit HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon& weapon);
};

#endif	// !__HUMAN_B__
