NAME = megaphone
SRC = Megaphone.cpp

all: $(NAME)

$(NAME):
	@c++ -Wall -Wextra -Werror $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all

format:
	@clang-format -i $(SRC)

.PHONY: all clean fclean re
