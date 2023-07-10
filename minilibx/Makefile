# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 14:24:12 by kamitsui          #+#    #+#              #
#    Updated: 2023/07/10 19:47:25 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minilibx

#MLX_PATH = mlx
MLX_PATH = minilibx_mms_20191025_beta
INC_DIR = $(MLX_PATH)
SRC_DIR = src
OBJ_DIR = obj

CC = clang
CF = -Wall -Wextra -Werror
MLX_CF = -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit

SRCS = \
	  square.c
#	  push_image_window.c
#	  hello_world.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

vpath %.c $(SRC_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -Wall -Wextra -Werror -I$(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) -o $(NAME) $(OBJS) -L $(MLX_PATH) $(MLX_CF) $(FLAMEWORK)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
