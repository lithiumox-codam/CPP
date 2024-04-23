NAME = fixed
SRC = main.cpp Fixed.cpp Fixed_ops.cpp
HEADERS = Fixed.hpp
BUILD_DIR = build
BUILD = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(BUILD_DIR) $(HEADERS)
	@c++ $(BUILD) -o $(NAME)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
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

.PHONY: all clean fclean re
