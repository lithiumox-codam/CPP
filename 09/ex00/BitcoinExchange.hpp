#pragma once

#include <cstdlib>
#include <map>
#include <string>

class BitcoinExchange {
   private:
	std::map<std::string, float> _data;
	bool _isValidDate(const std::string& date);
	bool _isValidValue(const std::string& valueStr, float& value);

   public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
	~BitcoinExchange();

	BitcoinExchange(const std::string& dbPath);

	void processInputFile(const std::string& inputPath);
};