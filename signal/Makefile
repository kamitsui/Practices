# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 12:53:07 by kamitsui          #+#    #+#              #
#    Updated: 2023/10/27 22:58:36 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target
NAME1 = 1_simple_sigaction
NAME2 = 2_sigterm

# Souce
SRC_1 = sigaction.c
OBJ_1 = $(SRC_1:%.c=%.o)
SRC_2 = sigterm_handle.c
OBJ_2 = $(SRC_2:%.c=%.o)

# Compile
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(ACTION): $(OBJ_1)
	$(CC) $(CFLAGS) $(OBJ_1) -o $@

$(SIGTERM): $(OBJ_2)
	$(CC) $(CFLAGS) $(OBJ_2) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJ_1) $(OBJ_2)

fclean: clean
	rm $(ACTION)
	rm $(SIGTERM)

.PHONY:
	all fclean clean
