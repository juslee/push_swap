# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 20:15:13 by welee             #+#    #+#              #
#    Updated: 2024/09/24 13:24:07 by welee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(BINS_DIR)/push_swap
BONUS_NAME = $(BINS_DIR)/checker
SRCS = $(wildcard $(SRCS_DIR)/stack/*.c) \
	   $(wildcard $(SRCS_DIR)/utils/*.c) \
	   $(wildcard $(SRCS_DIR)/operations/*.c) \
	   $(wildcard $(SRCS_DIR)/parser/*.c) \
	   $(wildcard $(SRCS_DIR)/sort/*.c) \
	   $(wildcard $(SRCS_DIR)/main.c)
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(MAIN_OBJS_DIR)/%.o)
INCS = $(wildcard $(INCS_DIR)/*.h)
BONUS_SRCS = $(wildcard $(SRCS_DIR)/stack/*.c) \
			 $(wildcard $(SRCS_DIR)/utils/*.c) \
			 $(wildcard $(SRCS_DIR)/operations/*.c) \
			 $(wildcard $(SRCS_DIR)/parser/*.c) \
			 $(wildcard $(SRCS_DIR)/bonus/*.c)
BONUS_OBJS = $(BONUS_SRCS:$(SRCS_DIR)/%.c=$(BONUS_OBJS_DIR)/%.o)

# Object directories for main and bonus
MAIN_OBJS_DIR = objs/main
BONUS_OBJS_DIR = objs/bonus

# Directory Variables ---------------------------------------------------------#
SRCS_DIR = srcs
INCS_DIR = includes
OBJS_DIR = objs
BINS_DIR = bin
TEST_DIR = tests
LIBS_DIR = libs
DIST_DIR = dist
DOCS_DIR = docs
# ---------------------------------------------------------------------------- #

# Library Variables -----------------------------------------------------------#
LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/bin/libft.a
LIBFT_LIB = -L$(LIBFT_DIR)/bin -lft
LIBFT_INC = $(LIBFT_DIR)/includes

GET_NEXT_LINE_DIR = $(LIBS_DIR)/get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/bin/libgnl.a
GET_NEXT_LINE_LIB = -L$(GET_NEXT_LINE_DIR)/bin -lgnl
GET_NEXT_LINE_INC = $(GET_NEXT_LINE_DIR)/includes
# ---------------------------------------------------------------------------- #

# Macro Variables -------------------------------------------------------------#
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCS_DIR) -I$(LIBFT_INC) -I$(GET_NEXT_LINE_INC)
TARGET = $(MAKECMDGOALS)
ifeq ($(TARGET), bonus)
	CFLAGS += -DWRITE_FLAG=0
else
	CFLAGS += -DWRITE_FLAG=1
endif
LIBC = ar rcs
RM = rm -f
MKDIR = mkdir -p
MAKE = make
CD = cd
CP = cp -r
ECHO = echo
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	SED := sed -i
else ifeq ($(UNAME_S),Darwin)
	SED := sed -i ''
else
	$(error Unsupported OS)
endif
WHOAMI = $(shell whoami)
# ---------------------------------------------------------------------------- #

# Tools Variables -------------------------------------------------------------#
NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

DOXYGEN = doxygen
DOXYGEN_CONFIG = Doxyfile
# ---------------------------------------------------------------------------- #

# Rules Definition -s----------------------------------------------------------#
all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(OBJS) | $(BINS_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)
	@$(ECHO) "\033[32m$(NAME) compiled\033[0m"

$(BONUS_NAME): $(LIBFT) $(GET_NEXT_LINE) $(BONUS_OBJS) | $(BINS_DIR)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(GET_NEXT_LINE_LIB) $(LIBFT_LIB)
	@$(ECHO) "\033[32m$(BONUS_NAME) compiled\033[0m"

$(BINS_DIR):
	$(MKDIR) $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GET_NEXT_LINE):
	$(MAKE) -C $(GET_NEXT_LINE_DIR)

$(MAIN_OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS) | $(MAIN_OBJS_DIR)
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	@$(ECHO) "\033[33mCompiled $@ with WRITE_FLAG=1\033[0m"

$(BONUS_OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS) | $(BONUS_OBJS_DIR)
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	@$(ECHO) "\033[33mCompiled $@ with WRITE_FLAG=0\033[0m"

$(MAIN_OBJS_DIR):
	$(MKDIR) $@

$(BONUS_OBJS_DIR):
	$(MKDIR) $@

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	@$(ECHO) "\033[31m$(NAME) object files removed\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(RM) -r $(DIST_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	@$(ECHO) "\033[31m$(NAME) removed\033[0m"

re: fclean all

tests: $(NAME)
	@$(ECHO) "\033[32mTest completed\033[0m"

norm:
	$(NORM) $(NORM_FLAGS) $(SRCS_DIR) $(INCS_DIR)
	@$(ECHO) "\033[32mNorm check completed\033[0m"

doxygen:
	@$(DOXYGEN) $(DOXYGEN_CONFIG)
	@$(ECHO) "\033[32mDoxygen generated\033[0m"

dist: fclean
	$(MKDIR) $(DIST_DIR)
	$(CP) $(SRCS_DIR) $(INCS_DIR) $(LIBS_DIR) $(DIST_DIR)
	$(CP) Makefile $(DIST_DIR)
	$(SED) 's|^NAME = $$(BINS_DIR)/push_swap$$|NAME = push_swap|' $(DIST_DIR)/Makefile
	$(SED) 's|^BONUS_NAME = $$(BINS_DIR)/checker$$|BONUS_NAME = checker|' $(DIST_DIR)/Makefile
	$(SED) '/^\$$(NAME):/ s/ | $$(BINS_DIR)//' $(DIST_DIR)/Makefile
	$(SED) '/^\$$(BONUS_NAME):/ s/ | $$(BINS_DIR)//' $(DIST_DIR)/Makefile
	@$(ECHO) "\033[32mDistribution files copied\033[0m"

.PHONY: all bonus clean fclean re norm doxygen dist
# ---------------------------------------------------------------------------- #
