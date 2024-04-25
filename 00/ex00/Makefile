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

run: all
	@printf "\n🤖 00/ex00 $(NAME) output:\n\n"
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME) "This is a test"
	./$(NAME)

.PHONY: all clean fclean re
