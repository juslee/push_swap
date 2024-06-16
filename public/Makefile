# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 10:40:32 by welee             #+#    #+#              #
#    Updated: 2024/06/16 09:12:32 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = $(shell find $(SRCS_DIR) -name '*.c')
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = -L $(LIBFT_DIR)/bin -lft
LIBFT_INC = -I $(LIBFT_DIR)/libft.h

SRCS_DIR = srcs
OBJS_DIR = objs
INCLUDES_DIR = includes
INCLUDES = -I ${INCLUDES_DIR}

CFLAGS = -Wall -Wextra -Werror
CC = cc
MKDIR = mkdir -p
RM = rm -f

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(LIBFT_INC) $(OBJS) -o $(NAME)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
