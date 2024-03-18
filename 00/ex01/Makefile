NAME = phonebook
SRC = src/phonebook.cpp src/contact.cpp

all: $(NAME)

$(NAME):
	@c++ -Wall -Wextra -Werror $(SRC) -I ./includes -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all

format:
	@clang-format -i $(SRC) $(HEADERS)

.PHONY: all clean fclean re
