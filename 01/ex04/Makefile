NAME = replace
SRC = main.cpp
BUILD_DIR = build
BUILD = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))
REPLACED = $(wildcard tests/*.replaced)

all: $(NAME)

$(NAME): $(BUILD_DIR) $(BUILD)
	@c++ $(BUILD) -o $(NAME)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@c++ -Werror -Wall -Wextra -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean:
	@rm -rf $(NAME)
	@rm -f $(REPLACED)

fclean: clean
	@rm -rf $(BUILD_DIR)

re: fclean all

format:
	@clang-format -i $(SRC) $(HEADERS)

run: all
	@printf "\n🤖 01/ex04 $(NAME) output:\n"
	@./test.sh

.PHONY: all clean fclean re
