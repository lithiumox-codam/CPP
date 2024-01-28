#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>

class Weapon {
   private:
	std::string type;

   public:
	Weapon(std::string type);
	~Weapon();
	void setType(std::string type);
	const std::string& getType();
};

#endif
