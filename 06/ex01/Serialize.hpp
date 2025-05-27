#pragma once

#include <stdint.h>

#include <string>

struct Data {
	std::string str;
	size_t num;
};

class Serialize {
   public:
	Serialize();
	Serialize(const Serialize&);
	Serialize& operator=(const Serialize&);
	~Serialize();
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};
