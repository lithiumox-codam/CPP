#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) { *this = src; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if (this != &rhs) {
		this->_data = rhs._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbPath) {
	std::ifstream dbFile(dbPath.c_str());
	if (!dbFile.is_open()) {
		throw std::runtime_error("Error: could not open database file.");
	}

	std::string line;
	std::getline(dbFile, line);

	if (line != "date,exchange_rate") {
		std::cerr << "Error: bad database format." << std::endl;
	}

	while (std::getline(dbFile, line)) {
		std::stringstream ss(line);
		std::string date;
		std::string rateStr;
		float rate;

		if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
			char* end;
			rate = std::strtof(rateStr.c_str(), &end);
			if (*end == '\0') this->_data[date] = rate;
		}
	}
}

bool BitcoinExchange::_isValidDate(const std::string& date) {
	if (date.length() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;

	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7) continue;
		if (!std::isdigit(date[i])) return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}

	return true;
}

bool BitcoinExchange::_isValidValue(const std::string& valueStr, float& value) {
	char* end;
	value = std::strtof(valueStr.c_str(), &end);

	while (*end != '\0' && std::isspace(*end)) {
		end++;
	}
	if (*end != '\0') return false;	 // Check if the entire string was consumed

	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::processInputFile(const std::string& inputPath) {
	std::ifstream inputFile(inputPath.c_str());
	if (!inputFile.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(inputFile, line);

	if (line != "date | value") {
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	while (std::getline(inputFile, line)) {
		std::stringstream ss(line);
		std::string date;
		std::string separator;
		std::string valueStr;

		ss >> date >> separator >> valueStr;

		if (date.empty() || separator != "|" || valueStr.empty()) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		float value;
		if (!_isValidDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (!_isValidValue(valueStr, value)) {
			continue;
		}

		// Find the exchange rate
		std::map<std::string, float>::iterator it = _data.lower_bound(date);

		if (it == _data.end() || it->first != date) {
			if (it == _data.begin()) {
				std::cout << "Error: no data available for or before " << date << std::endl;
				continue;
			}
			--it;  // Decrement to get the closest earlier date
		}

		float exchangeRate = it->second;
		std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
	}
}