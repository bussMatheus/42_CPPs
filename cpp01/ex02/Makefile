NAME	= HI_THIS_IS_BRAIN

SRC		= main.cpp
OBJ_DIR	= obj
OBJ		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

CPP		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

#Colors
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✔ Compiled$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Cleaned obj files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Cleaned all.$(RESET)"

re: fclean all

.PHONY: all clean fclean re