#include <cassert>
#include <iostream>

#include "Serialize.hpp"

/**
 * @brief The main function demonstrates serialization and deserialization of a Data structure.
 * This example creates a Data object, serializes it to a raw pointer, then deserializes it back to a Data
 * object.
 */
int main(void) {
	Data data;
	data.str = "Hello, World!";
	data.num = 42;

	Serialize serializer;

	// Serialize the data
	uintptr_t raw = serializer.serialize(&data);
	std::cout << "Serialized data to raw pointer: " << raw << std::endl;

	// Deserialize the raw pointer back to Data
	Data* deserializedData = serializer.deserialize(raw);
	std::cout << "Deserialized data: " << deserializedData->str << ", " << deserializedData->num << std::endl;

	// Assert to ensure the deserialized data matches the original (fails when the code is incorrect)
	assert(deserializedData->str == data.str);

	return 0;
}