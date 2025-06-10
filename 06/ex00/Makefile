NAME = convert
SRC = ScalarConverter.cpp  main.cpp
HEADERS = ScalarConverter.hpp
BUILD_DIR = build
BUILD = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(BUILD_DIR) $(BUILD)
	@c++ $(BUILD) -o $(NAME)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@c++ -Werror -Wall -Wextra -Wno-implicit-fallthrough -std=c++23 -c $< -o $@

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
	@printf "\n🤖 06/ex00 $(NAME) output:\n\n"
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f
	./$(NAME) 42
	./$(NAME) 42.42
	./$(NAME) 36
	./$(NAME) -inf
	./$(NAME) +inf


.PHONY: all clean fclean re
