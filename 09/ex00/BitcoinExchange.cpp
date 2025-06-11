#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {
	// Constructor implementation
}

BitcoinExchange::~BitcoinExchange() {
	// Destructor implementation
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : data(other.data) {
	// Copy constructor implementation
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		data = other.data;
	}
	return *this;
}

void BitcoinExchange::parseLine(const std::string &line) {
	std::istringstream stream(line);
	std::string date, valueStr;
	if (std::getline(stream, date, ',') && std::getline(stream, valueStr)) {
		float value = std::stof(valueStr);
		validateDate(date);
		validateValue(value);
		addValue(date, value);
	}
}

/**
 * @brief When loading data from the data.csv file, we need to do ',' splitting.
 * This is not the same as the splitting in the input.txt file, which uses '|' as a separator.
 *
 * @param filename
 * @param splitChars
 */
void BitcoinExchange::loadData(const std::string &filename, const std::string &splitChars) {
	std::ifstream file(filename);
	std::string line;

	if (!file.is_open()) {
		throw std::runtime_error("Could not open file: " + filename);
	}

	// check the first line (either "date, value" or "date | value")
	if (std::getline(file, line)) {
		if (line.find(',') != std::string::npos) {
			// If the line contains a comma, we assume it's a CSV format
			while (std::getline(file, line)) {
				parseLine(line);
			}
		} else if (line.find('|') != std::string::npos) {
			// If the line contains a pipe, we assume it's a different format
			while (std::getline(file, line)) {
				std::replace(line.begin(), line.end(), '|', ',');
				parseLine(line);
			}
		} else {
			throw std::runtime_error("Unknown file format in: " + filename);
		}
	}
}