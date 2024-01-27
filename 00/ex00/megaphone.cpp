#include <stdlib.h>

#include <iostream>
#include <string>

int main(int ac, char **av) {
  if (ac == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    return 0;
  }
  for (int i = 1; i < ac; i++) {
    std::string str = av[i];
    for (size_t j = 0; j < str.length(); j++) {
      if (isalpha(str[j])) str[j] = toupper(str[j]);
    }
    std::cout << str;
  }
}
