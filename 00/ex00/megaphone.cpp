#include <iostream>
#include <stdlib.h>
#include <string>

int main(int ac, char **av) {
  for (int i = 1; i < ac; i++) {
    std::string str = av[i];
    for (size_t j = 0; j < str.length(); j++) {
      if (isalpha(str[j]))
        str[j] = toupper(str[j]);
    }
    std::cout << str;
  }
}
