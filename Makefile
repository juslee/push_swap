# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 20:15:13 by welee             #+#    #+#              #
#    Updated: 2024/08/05 16:39:18 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(BINS_DIR)/push_swap
BONUS_NAME = $(BINS_DIR)/checker

SRCS_DIR = srcs
INCS_DIR = includes
OBJS_DIR = objs
BINS_DIR = bin
LIBS_DIR = libs
DIST_DIR = dist
PUBL_DIR = public

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
CP = cp -r

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(OBJS) | $(BINS_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

$(BONUS_NAME): $(LIBFT) $(GET_NEXT_LINE) $(BONUS_OBJS) | $(BINS_DIR)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(GET_NEXT_LINE_LIB) $(LIBFT_LIB)

$(BINS_DIR):
	$(MKDIR) $@

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
	$(RM) -r $(DIST_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean

re: fclean all

norm:
	$(NORM) $(NORM_FLAGS) $(SRCS_DIR) $(INCS_DIR) $(PUBL_DIR)

dist: fclean
	$(MKDIR) $(DIST_DIR)
	$(MKDIR) $(DIST_DIR)/$(SRCS_DIR)
	$(MKDIR) $(DIST_DIR)/$(INCS_DIR)
	$(MKDIR) $(DIST_DIR)/$(LIBFT_DIR)
	$(MKDIR) $(DIST_DIR)/$(GET_NEXT_LINE_DIR)
	$(CP) $(SRCS_DIR)/* $(DIST_DIR)/$(SRCS_DIR)
	$(CP) $(INCS_DIR)/* $(DIST_DIR)/$(INCS_DIR)
	$(CP) $(LIBFT_DIR)/* $(DIST_DIR)/$(LIBFT_DIR)
	$(CP) $(GET_NEXT_LINE_DIR)/* $(DIST_DIR)/$(GET_NEXT_LINE_DIR)
	$(CP) $(PUBL_DIR)/Makefile $(DIST_DIR)

.PHONY: all clean fclean re norm bonus dist
