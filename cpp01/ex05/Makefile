NAME = Harl
SRC = main.cpp Harl.cpp
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