# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 10:00:11 by welee             #+#    #+#              #
#    Updated: 2024/06/17 19:23:26 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
LIBFT_DIR = ../libft
INCLUDES_DIR = ../includes
OBJS_DIR = objs
BIN_DIR = bin
SRC_DIR = .

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = -L $(LIBFT_DIR)/bin -lft
LIBFT_INC = -I $(LIBFT_DIR)/bin
INCLUDES = -I $(INCLUDES_DIR)

# Find all .c files in the test directory structure
TESTS = $(shell find $(SRC_DIR) -name '*.c')

# Object files and executables
OBJS = $(TESTS:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)
EXECS = $(TESTS:$(SRC_DIR)/%.c=$(BIN_DIR)/%_test)

# Targets
all: run_tests

run_tests: $(EXECS)
	@for exec in $(EXECS); do \
		$$exec; \
		rm -f $$exec; \
	done

$(EXECS): $(BIN_DIR)/%_test: $(SRC_DIR)/%.c $(LIBFT_DIR)/bin/libft.a
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT_INC) $(LIBFT) $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) -r $(BIN_DIR)

re: fclean all

.PHONY: all run_tests clean fclean re
