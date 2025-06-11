#pragma once

#include <map>
#include <string>

class BitcoinExchange {
   public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void loadData(const std::string &filename, const std::string &splitChars);
	float getValue(const std::string &date) const;
	void printAllValues() const;
	void printValue(const std::string &date) const;
	void addValue(const std::string &date, float value);
	void removeValue(const std::string &date);
	void clearData();
	bool isValidValue(float value) const;
	std::map<std::string, float> getData() const;

   private:
	std::map<std::string, float> data;

	void parseLine(const std::string &line);
	void validateDate(const std::string &date) const;
	void validateValue(float value) const;
};