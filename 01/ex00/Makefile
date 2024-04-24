NAME = zombie
SRC = newZombie.cpp randomChump.cpp Zombie.cpp main.cpp
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

run: all
	@printf "\n🤖 01/ex00 $(NAME) output:\n\n"
	@./$(NAME)

.PHONY: all clean fclean re
