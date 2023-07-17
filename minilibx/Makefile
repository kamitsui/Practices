# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 14:24:12 by kamitsui          #+#    #+#              #
#    Updated: 2023/07/16 22:33:15 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5) $(NAME6)
NAME1 = my_window
NAME2 = push_image_window
NAME3 = square
NAME4 = circle
NAME5 = wireframe
NAME6 = image

#MLX_PATH = /Users/kamitsui/lib
MLX_PATH = /Users/kamitsui/lib/minilibx/minilibx_macos
#LIB_MLX = $(MLX_PATH)/libmlx.dylib
LIB_MLX = $(MLX_PATH)/libmlx.a
SRC_DIR = src
OBJ_DIR = obj

CC = clang
CF = -Wall -Wextra -Werror
INCLUDE = -I$(MLX_PATH)
MLX_CF = -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit

SRC1 = my_window.c
SRC2 = push_image_window.c
SRC3 = square.c
SRC4 = circle.c
SRC5 = wireframe.c
SRC6 = use_image.c

OBJ1 = $(addprefix $(OBJ_DIR)/, $(SRC1:.c=.o))
OBJ2 = $(addprefix $(OBJ_DIR)/, $(SRC2:.c=.o))
OBJ3 = $(addprefix $(OBJ_DIR)/, $(SRC3:.c=.o))
OBJ4 = $(addprefix $(OBJ_DIR)/, $(SRC4:.c=.o))
OBJ5 = $(addprefix $(OBJ_DIR)/, $(SRC5:.c=.o))
OBJ6 = $(addprefix $(OBJ_DIR)/, $(SRC6:.c=.o))

vpath %.c $(SRC_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CF) $(INCLUDE) -c $< -o $@

all: $(TARGET)

$(NAME1): $(OBJ1) $(LIB_MLX)
#	$(CC) -o $(NAME1) $(OBJ1) -L $(MLX_PATH) $(MLX_CF)
	$(CC) -o $(NAME1) $(OBJ1) $(LIB_MLX) $(FRAMEWORK)

$(NAME2): $(OBJ2) $(LIB_MLX)
#	$(CC) -o $(NAME2) $(OBJ2) -L $(MLX_PATH) $(MLX_CF)
	$(CC) -o $(NAME2) $(OBJ2) $(LIB_MLX) $(FRAMEWORK)

$(NAME3): $(OBJ3) $(LIB_MLX)
#	$(CC) -o $(NAME3) $(OBJ3) -L $(MLX_PATH) $(MLX_CF)
	$(CC) -o $(NAME3) $(OBJ3) $(LIB_MLX) $(FRAMEWORK)

$(NAME4): $(OBJ4) $(LIB_MLX)
#	$(CC) -o $(NAME4) $(OBJ4) -L $(MLX_PATH) $(MLX_CF)
	$(CC) -o $(NAME4) $(OBJ4) $(LIB_MLX) $(FRAMEWORK)

$(NAME5): $(OBJ5) $(LIB_MLX)
#	$(CC) -o $(NAME4) $(OBJ4) -L $(MLX_PATH) $(MLX_CF)
	$(CC) -o $(NAME5) $(OBJ5) $(LIB_MLX) $(FRAMEWORK)

$(NAME6): $(OBJ6) $(LIB_MLX)
#	$(CC) -o $(NAME4) $(OBJ4) -L $(MLX_PATH) $(MLX_CF)
	$(CC) -o $(NAME6) $(OBJ6) $(LIB_MLX) $(FRAMEWORK)

#$(MLX_DYLB):
#	@printf "Please install libmlx.dylb"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
