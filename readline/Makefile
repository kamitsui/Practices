# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 12:53:07 by kamitsui          #+#    #+#              #
#    Updated: 2023/09/30 15:08:29 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target
HISTORY = history
READLINE = readline

# Souce
SRC_H = history.c
OBJ_H = $(SRC_H:%.c=%.o)
SRC_RL = readline.c
OBJ_RL = $(SRC_RL:%.c=%.o)

# Directorys
LIB_RL = libreadline.dylib
LIB_RL_DYLIB_PATH = $(shell find /opt/homebrew -name $(LIB_RL) 2>/dev/null)
LIB_RL_LIB_DIR = $(dir $(LIB_RL_DYLIB_PATH))
LIB_RL_INC_DIR = $(subst /lib/,/include,$(LIB_RL_LIB_DIR))

# Compile
CC = cc
CFLAGS = $(CF_LINK) $(CF_DYLIB) $(CF_INC)
CF_LINK = -lreadline
CF_DYLIB = -L$(LIB_RL_LIB_DIR)
CF_INC = -I$(LIB_RL_INC_DIR)

all: $(HISTORY) $(READLINE)

$(HISTORY): $(OBJ_H)
	$(CC) $(CFLAGS) $(OBJ_H) -o $@

$(READLINE): $(OBJ_RL)
	$(CC) $(CFLAGS) $(OBJ_RL) -o $@

%.o: %.c
	$(CC) $(CF_INC) -c $< -o $@

clean:
	rm $(OBJ_H) $(OBJ_RL)

fclean: clean
	rm $(HISTORY) $(READLINE)

.PHONY:
	all fclean clean history readline
