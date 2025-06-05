#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
	std::srand(
		std::time(0) +
		reinterpret_cast<long>(new int));  // Seed with time + a new address for better randomness in quick successions
	int choice = std::rand() % 3;
	if (choice == 0) {
		return new A();
	} else if (choice == 1) {
		return new B();
	} else {
		return new C();
	}
}

void identify(Base* p) {
	if (p == nullptr) {
		std::cout << "Null pointer" << std::endl;
		return;
	}

	try {
		if (dynamic_cast<A*>(p)) {
			std::cout << "A" << std::endl;
		} else if (dynamic_cast<B*>(p)) {
			std::cout << "B" << std::endl;
		} else if (dynamic_cast<C*>(p)) {
			std::cout << "C" << std::endl;
		} else {
			std::cout << "Unknown type" << std::endl;
		}
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;  // To avoid unused variable warning
		return;
	} catch (const std::exception& e) {
	}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;  // To avoid unused variable warning
		return;
	} catch (const std::exception& e) {
	}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;  // To avoid unused variable warning
		return;
	} catch (const std::exception& e) {
	}
}
