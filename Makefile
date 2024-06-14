# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 10:00:11 by welee             #+#    #+#              #
#    Updated: 2024/06/14 16:28:07 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = $(shell find $(SRCS_DIR) -name '*.c')
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

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

all: $(NAME)
$(NAME): $(OBJS)
	$(MKDIR) $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(BIN_DIR)/$(NAME)
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
tests: $(NAME)
	$(MAKE) $(TEST_DIR)
dist:
	$(MKDIR) $(DIST_DIR)
	$(CP) $(PUBLIC_DIR)/Makefile $(DIST_DIR)/Makefile
	$(CP) $(SRCS_DIR) $(DIST_DIR)
	$(CP) $(INCLUDES_DIR) $(DIST_DIR)
	$(ECHO) $(WHOAMI) > $(DIST_DIR)/author
	$(ECHO) "Dist created in $(DIST_DIR)"
docs:
	$(MKDIR) $(DOCS_DIR)
	$(DOXYGEN) $(DOXYGEN_CONFIG)
.PHONY: all clean fclean re norm tests dist
