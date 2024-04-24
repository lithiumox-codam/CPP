NAME = harlFilter
SRC = main.cpp Harl.cpp
HEADERS = Harl.hpp
BUILD_DIR = build
BUILD = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(BUILD_DIR) $(BUILD)
	@c++ $(BUILD) -o $(NAME)

$(BUILD_DIR)/%.o: %.cpp $(HEADERS) | $(BUILD_DIR)
	@c++ -Werror -Wall -Wextra -Wno-implicit-fallthrough -c $< -o $@

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
	@printf "\n🤖 01/ex06 $(NAME) output:\n\n"
	./$(NAME) DEBUG
	./$(NAME) INFO
	./$(NAME) WARNING
	./$(NAME) ERROR
	./$(NAME) RANDOM

.PHONY: all clean fclean re
