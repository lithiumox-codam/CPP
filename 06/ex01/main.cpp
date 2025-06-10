#include <cassert>
#include <iostream>

#include "Serialize.hpp"

/**
 * @brief The main function demonstrates serialization and deserialization of a Data structure.
 * This example creates a Data object, serializes it to a raw pointer, then deserializes it back to a Data
 * object.
 */
int main(void) {
	Data data = {"Hello, World!", 42};

	// Serialize the data
	uintptr_t raw = Serialize::serialize(&data);
	std::cout << "Serialized data to raw pointer: " << raw << std::endl;

	// Deserialize the raw pointer back to Data
	Data* deserializedData = Serialize::deserialize(raw);
	std::cout << "Deserialized data: " << deserializedData->str << ", " << deserializedData->num << std::endl;

	std::cout << "Asserting that the deserialized data matches the original data...";
	assert(deserializedData->str == data.str);
	std::cout << " ✅" << std::endl;

	return 0;
}