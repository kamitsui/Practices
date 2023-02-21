NAME = test
CC = clang
FLAGS = -Wall -Wextra -Werror -g
SRC = main.c
LIBFT = ../../Libft/libft/libft.a
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $<

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all
