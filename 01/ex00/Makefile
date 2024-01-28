NAME = zombie
SRC = newZombie.cpp randomChump.cpp zombie.cpp main.cpp

all: $(NAME)

$(NAME):
	@c++ -Wall -Wextra -Werror $(SRC) -I . -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all

format:
	@clang-format -i $(SRC) $(HEADERS)

.PHONY: all clean fclean re
