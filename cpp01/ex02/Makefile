NAME = HI_THIS_IS_BRAIN
SRC = main.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)
	@echo "Cleaned up."

re: clean all

.PHONY: all clean re