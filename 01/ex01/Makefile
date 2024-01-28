NAME = zombie
SRC = Zombie.cpp main.cpp zombieHorde.cpp
HEADERS = Zombie.hpp

all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	@c++ -Wall -Wextra -Werror $(SRC) -I . -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all

format:
	@clang-format -i $(SRC) $(HEADERS)

.PHONY: all clean fclean re
