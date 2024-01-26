NAME = phonebook
SRC = phonebook.cpp
HEADERS = phonebook.hpp

all: $(NAME)

$(NAME):
	@clang++ -Wall -Wextra -Werror $(SRC) -I $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
