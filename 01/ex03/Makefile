NAME = humans
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp
BUILD_DIR = build
BUILD = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(BUILD_DIR) $(BUILD) $(HEADERS)
	@c++ $(BUILD) -o $(NAME)

$(BUILD_DIR)/%.o: %.cpp $(SRC) $(HEADERS) | $(BUILD_DIR)
	@c++ -Werror -Wall -Wextra -c $< -o $@

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
	@printf "\n🤖 01/ex03 $(NAME) output:\n\n"
	@./$(NAME)

.PHONY: all clean fclean re
