# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 20:15:13 by welee             #+#    #+#              #
#    Updated: 2024/07/26 21:05:19 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = objs

SRCS = $(wildcard $(SRC_DIR)/stack/*.c) \
	   $(wildcard $(SRC_DIR)/utils/*.c) \
	   $(wildcard $(SRC_DIR)/operations/*.c) \
	   $(wildcard $(SRC_DIR)/parser/*.c) \
	   $(wildcard $(SRC_DIR)/sort/*.c) \
	   $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
