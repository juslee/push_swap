# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 20:15:13 by welee             #+#    #+#              #
#    Updated: 2024/08/05 16:43:15 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

SRCS_DIR = srcs
INCS_DIR = includes
OBJS_DIR = objs
LIBS_DIR = libs

LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/bin/libft.a
LIBFT_LIB = -L$(LIBFT_DIR)/bin -lft
LIBFT_INC = $(LIBFT_DIR)/includes
SRCS = $(wildcard $(SRCS_DIR)/stack/*.c) \
	   $(wildcard $(SRCS_DIR)/utils/*.c) \
	   $(wildcard $(SRCS_DIR)/operations/*.c) \
	   $(wildcard $(SRCS_DIR)/parser/*.c) \
	   $(wildcard $(SRCS_DIR)/sort/*.c) \
	   $(wildcard $(SRCS_DIR)/main.c)
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

GET_NEXT_LINE_DIR = $(LIBS_DIR)/get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/bin/libgnl.a
GET_NEXT_LINE_LIB = -L$(GET_NEXT_LINE_DIR)/bin -lgnl
GET_NEXT_LINE_INC = $(GET_NEXT_LINE_DIR)/includes
BONUS_SRCS = $(wildcard $(SRCS_DIR)/stack/*.c) \
			 $(wildcard $(SRCS_DIR)/utils/*.c) \
			 $(wildcard $(SRCS_DIR)/operations/*.c) \
			 $(wildcard $(SRCS_DIR)/parser/*.c) \
			 $(wildcard $(SRCS_DIR)/bonus/*.c)
BONUS_OBJS = $(BONUS_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCS_DIR) -I$(LIBFT_INC) -I$(GET_NEXT_LINE_INC)
RM = rm -f
MKDIR = mkdir -p

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

$(BONUS_NAME): $(LIBFT) $(GET_NEXT_LINE) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(GET_NEXT_LINE_LIB) $(LIBFT_LIB)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GET_NEXT_LINE):
	$(MAKE) -C $(GET_NEXT_LINE_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
