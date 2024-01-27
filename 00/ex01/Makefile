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

format:
	@clang-format -i $(SRC) $(HEADERS)

.PHONY: all clean fclean re
