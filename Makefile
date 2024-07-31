# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 20:15:13 by welee             #+#    #+#              #
#    Updated: 2024/07/31 23:39:06 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bin/push_swap
BONUS_NAME = bin/checker

SRCS_DIR = srcs
INCS_DIR = includes
OBJS_DIR = objs
PUBLIC_DIR = public

LIBFT = libft/bin/libft.a
LIBFT_LIB = -Llibft/bin -lft
LIBFT_INC = libft/includes
SRCS = $(wildcard $(SRCS_DIR)/stack/*.c) \
	   $(wildcard $(SRCS_DIR)/utils/*.c) \
	   $(wildcard $(SRCS_DIR)/operations/*.c) \
	   $(wildcard $(SRCS_DIR)/parser/*.c) \
	   $(wildcard $(SRCS_DIR)/sort/*.c) \
	   $(wildcard $(SRCS_DIR)/main.c)
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

GET_NEXT_LINE = get_next_line/bin/libgnl.a
GET_NEXT_LINE_LIB = -Lget_next_line/bin -lgnl
GET_NEXT_LINE_INC = get_next_line/includes
BONUS_SRCS = $(wildcard $(SRCS_DIR)/stack/*.c) \
			 $(wildcard $(SRCS_DIR)/utils/*.c) \
			 $(wildcard $(SRCS_DIR)/operations/*.c) \
			 $(wildcard $(SRCS_DIR)/parser/*.c) \
			 $(wildcard $(SRCS_DIR)/bonus/*.c)
BONUS_OBJS = $(BONUS_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCS_DIR) -I$(LIBFT_INC) -I$(GET_NEXT_LINE_INC)
RM = rm -f

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

bonus: $(LIBFT) $(GET_NEXT_LINE) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(GET_NEXT_LINE_LIB) $(LIBFT_LIB)

$(LIBFT):
	$(MAKE) -C libft

$(GET_NEXT_LINE):
	$(MAKE) -C get_next_line

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C get_next_line clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C get_next_line fclean

re: fclean all

norm:
	$(NORM) $(NORM_FLAGS) $(SRCS_DIR) $(INCS_DIR) $(PUBLIC_DIR)

.PHONY: all clean fclean re
