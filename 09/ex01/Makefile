NAME = RPN
SRC = main.cpp RPN.cpp
HEADERS = RPN.hpp
BUILD_DIR = build
BUILD = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(BUILD_DIR) $(BUILD)
	@c++ -Werror -Wall -Wextra $(BUILD) -o $(NAME)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@c++ -Werror -Wall -Wextra -Wno-implicit-fallthrough -std=c++17 -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -rf $(BUILD_DIR)

re: fclean all

format:
	@clang-format -i $(SRC) $(HEADERS)

run: all
	@printf "\n🤖 09/ex00 $(NAME) output:\n\n"
	@printf "\nTest: \"8 9 * 9 - 9 - 9 - 4 - 1 +\"\n"
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@printf "\nTest: \"7 7 * 7 -\"\n"
	@./$(NAME) "7 7 * 7 -"
	@printf "\nTest: \"1 2 * 2 / 2 * 2 4 - +\"\n"
	@./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@printf "\nTest: \"(1 + 1)\"\n"
	@./$(NAME) "(1 + 1)"

.PHONY: all clean fclean re format run
