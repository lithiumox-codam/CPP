NAME = btc
SRC = main.cpp BitcoinExchange.cpp
HEADERS = BitcoinExchange.hpp
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
	@printf "\nDefault input file: input.txt\n\n"
	@./$(NAME) input.txt
	@printf "\nCustom input file: correct_input.txt\n\n"
	@./$(NAME) correct_input.txt

.PHONY: all clean fclean re format run

