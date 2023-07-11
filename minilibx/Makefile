# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 14:24:12 by kamitsui          #+#    #+#              #
#    Updated: 2023/07/11 19:32:59 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = $(NAME1) $(NAME2) $(NAME3)
NAME1 = my_window
NAME2 = push_image_window
NAME3 = square

MLX_PATH = /Users/kamitsui/lib
MLX_DYLB = $(MLX_PATH)/libmlx.dylib
SRC_DIR = src
OBJ_DIR = obj

CC = clang
CF = -Wall -Wextra -Werror
MLX_CF = -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit

SRC1 = my_window.c
SRC2 = push_image_window.c
SRC3 = square.c

OBJ1 = $(addprefix $(OBJ_DIR)/, $(SRC1:.c=.o))
OBJ2 = $(addprefix $(OBJ_DIR)/, $(SRC2:.c=.o))
OBJ3 = $(addprefix $(OBJ_DIR)/, $(SRC3:.c=.o))

vpath %.c $(SRC_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: $(TARGET)

$(NAME1): $(OBJ1) $(MLX_DYLB)
	$(CC) -o $(NAME1) $(OBJ1) -L $(MLX_PATH) $(MLX_CF)

$(NAME2): $(OBJ2) $(MLX_DYLB)
	$(CC) -o $(NAME2) $(OBJ2) -L $(MLX_PATH) $(MLX_CF)

$(NAME3): $(OBJ3) $(MLX_DYLB)
	$(CC) -o $(NAME3) $(OBJ3) -L $(MLX_PATH) $(MLX_CF)

#$(MLX_DYLB):
#	@printf "Please install libmlx.dylb"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
