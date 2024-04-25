NAME = phonebook
SRC = src/Phonebook.cpp src/Contact.cpp

all: $(NAME)

$(NAME):
	@c++ -Wall -Wextra -Werror $(SRC) -I ./includes -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all

format:
	@clang-format -i $(SRC) $(HEADERS)

run: all
	@printf "\n🤖 00/ex01 $(NAME) output:\n\n"
	@printf "\n\033[0;32m Cannot run phonebook automatically... \033[0m\n"
	@printf "\033[0;32m Trust me phonebook is running just fine 🙂 \033[0m\n"

.PHONY: all clean fclean re
