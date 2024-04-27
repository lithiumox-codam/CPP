NAME = polymorphism
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
HEADERS = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp
BUILD_DIR = build
BUILD = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(BUILD_DIR) $(BUILD)
	@c++ $(BUILD) -o $(NAME)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@c++ -Werror -Wall -Wextra -Wno-implicit-fallthrough -std=c++11 -c $< -o $@

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
	@printf "\n🤖 04/ex01 $(NAME) output:\n\n"
	@./$(NAME)

.PHONY: all clean fclean re
