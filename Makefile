# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 10:00:11 by welee             #+#    #+#              #
#    Updated: 2024/06/16 09:10:00 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = $(shell find $(SRCS_DIR) -name '*.c')
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = -L $(LIBFT_DIR)/bin -lft
LIBFT_INC = -I $(LIBFT_DIR)/libft.h

PUBLIC_DIR = public
SRCS_DIR = srcs
OBJS_DIR = objs
INCLUDES_DIR = includes
TEST_DIR = tests
DIST_DIR = dist
BIN_DIR = bin
DOCS_DIR = docs

INCLUDES = -I ${INCLUDES_DIR}
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
MKDIR = mkdir -p
MAKE = make -C
CD = cd
CP = cp -r
ECHO = echo
FRANCINETTE = francinette
FRANCINETTE_FLAGS = -s
WHOAMI = $(shell whoami)

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

DOXYGEN = doxygen
DOXYGEN_CONFIG = Doxyfile

all: $(LIBFT_DIR) $(NAME)
$(NAME): $(OBJS)
	$(MKDIR) $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(LIBFT_INC) $(OBJS) -o $(BIN_DIR)/$(NAME)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
norm:
	$(NORM) $(NORM_FLAGS) $(SRCS_DIR) $(INCLUDES_DIR)
$(TEST_DIR): $(NAME)
	$(MAKE) $(TEST_DIR)
$(DIST_DIR):
	$(MKDIR) $(DIST_DIR)
	$(CP) $(PUBLIC_DIR)/Makefile $(DIST_DIR)/Makefile
	$(CP) $(SRCS_DIR) $(DIST_DIR)
	$(CP) $(INCLUDES_DIR) $(DIST_DIR)
	$(CP) $(LIBFT_DIR) $(DIST_DIR)
	$(ECHO) $(WHOAMI) > $(DIST_DIR)/author
	$(ECHO) "Dist created in $(DIST_DIR)"
$(DOCS_DIR):
	$(MKDIR) $(DOCS_DIR)
	$(DOXYGEN) $(DOXYGEN_CONFIG)
$(LIBFT_DIR):
	$(MAKE) $(LIBFT_DIR) fclean
.PHONY: all clean fclean re norm tests dist
