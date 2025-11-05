NAME	=	btc
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp BitcoinExchange.cpp
OBJ_DIR =	obj
OBJ		=	$(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re