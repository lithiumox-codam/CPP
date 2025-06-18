NAME = PmergeMe
SRC = main.cpp
HEADERS = PmergeMe.hpp
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
	@printf "\n🤖 08/ex02 $(NAME) output:\n\n"
	@./test.sh

.PHONY: all clean fclean re format run
