#include <fstream>
#include <iostream>
#include <string>

/**
 * @brief Replace all occurences of s1 in s by s2
 * @param s The string to modify
 * @param s1 The string to replace
 * @param s2 The string to replace with
 * @return The modified string
 */
std::string replace(std::string s, std::string s1, std::string s2) {
	std::string ret;
	size_t pos = 0;
	while (pos < s.size()) {
		size_t next = s.find(s1, pos);
		if (next == std::string::npos) {
			ret += s.substr(pos);
			break;
		}
		ret += s.substr(pos, next - pos);
		ret += s2;
		pos = next + s1.size();
	}
	return ret;
}

/**
 * @brief Replace all occurences of s1 in the file av[1] by s2
 * and write the result in the file "replaced.txt"
 * @param ac The number of arguments
 * @param av The arguments
 */
int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	std::ifstream ifs(av[1]);
	if (!ifs) {
		std::cout << "File does not exist" << std::endl;
		return 1;
	}
	std::string outfilename(av[1]);
	outfilename += ".replaced";
	std::ofstream ofs(outfilename, std::ios_base::trunc);
	if (!ofs) {
		std::cout << "Could not open output file" << std::endl;
		return 1;
	}
	std::string s1(av[2]);
	std::string s2(av[3]);
	std::string s;
	while (std::getline(ifs, s)) {
		s = replace(s, s1, s2);
		ofs << s << std::endl;
	}
	return 0;
}
