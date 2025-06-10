#pragma once

#include <stdint.h>

#include <string>

struct Data {
	std::string str;
	size_t num;
};

class Serialize {
   private:
	Serialize() = delete;
	Serialize(const Serialize&) = delete;
	Serialize& operator=(const Serialize&) = delete;
	~Serialize() = delete;

   public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
