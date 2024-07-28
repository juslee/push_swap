# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 20:15:13 by welee             #+#    #+#              #
#    Updated: 2024/07/27 19:46:08 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = objs

LIBFT = libft/bin/libft.a
LIBFT_INC = libft/includes
SRCS = $(wildcard $(SRC_DIR)/stack/*.c) \
	   $(wildcard $(SRC_DIR)/utils/*.c) \
	   $(wildcard $(SRC_DIR)/operations/*.c) \
	   $(wildcard $(SRC_DIR)/parser/*.c) \
	   $(wildcard $(SRC_DIR)/sort/*.c) \
	   $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_INC)
RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
