NAME = ptr
SRC = main.cpp

all: $(NAME)

$(NAME): $(SRC)
	@c++ -Wall -Wextra -Werror $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all

format:
	@clang-format -i $(SRC)

run: all
	@printf "\n🤖 01/ex02 $(NAME) output:\n\n"
	@./$(NAME)

.PHONY: all clean fclean re
