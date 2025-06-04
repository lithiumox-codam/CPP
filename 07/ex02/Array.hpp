#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array {
   private:
	T* _elements;
	unsigned int _size;

   public:
	Array() : _elements(nullptr), _size(0) {}
	Array(unsigned int n) : _size(n) { _elements = new T[n](); }

	Array(const Array& other) : _size(other._size) {
		_elements = new T[_size]();
		for (unsigned int i = 0; i < _size; i++) {
			_elements[i] = other._elements[i];
		}
	}

	~Array() { delete[] _elements; }

	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] _elements;
			_size = other._size;
			_elements = new T[_size]();
			for (unsigned int i = 0; i < _size; i++) {
				_elements[i] = other._elements[i];
			}
		}
		return *this;
	}

	// Subscript operator
	T& operator[](unsigned int index) {
		if (index >= _size) {
			throw std::exception();
		}
		return _elements[index];
	}

	// Const subscript operator
	const T& operator[](unsigned int index) const {
		if (index >= _size) {
			throw std::exception();
		}
		return _elements[index];
	}

	// Size method
	unsigned int size() const { return _size; }
};

#endif