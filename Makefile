# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/11 14:31:34 by nalysann          #+#    #+#              #
#    Updated: 2020/10/11 14:31:35 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM := asm
CRW := corewar

# **************************************************************************** #

ASM_DIR := asm

ASM_SRC :=

ASM_SRC := $(addprefix $(ASM_DIR)/, $(ASM_SRC))
ASM_OBJ := $(ASM_SRC:.c=.o)
ASM_DEP := $(ASM_SRC:.c=.d)

# **************************************************************************** #

CRW_DIR := corewar

CRW_SRC :=

CRW_SRC := $(addprefix $(CRW_SRC)/, $(CRW_SRC))
CRW_OBJ := $(CRW_SRC:.c=.o)
CRW_DEP := $(CRW_SRC:.c=.d)

# **************************************************************************** #

SRC_DIR := src

INC_DIR := include \
           $(FT_DIR)/include

OBJ_DIR := obj

SRC := $(addprefix $(SRC_DIR)/, $(ASM_SRC) $(CRW_SRC))
OBJ := $(addprefix $(OBJ_DIR)/, $(ASM_OBJ) $(CRW_OBJ))
DEP := $(addprefix $(OBJ_DIR)/, $(ASM_DEP) $(CRW_DEP))

# **************************************************************************** #

FT_DIR := libft

FT := libft.a

# **************************************************************************** #

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	CC := clang
endif

ifeq ($(UNAME_S), Linux)
	CC := gcc
endif

# **************************************************************************** #

CFLAGS += -Wall -Wextra -Werror \
          $(addprefix -I , $(INC_DIR)) \
          -MD \
          -march=native -O2 -pipe

LDFLAGS += -L $(FT_DIR)

LDLIBS += -lft

# **************************************************************************** #

RESET   := \033[0;0m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m
WHITE   := \033[0;37m

# **************************************************************************** #

.PHONY: all clean fclean re

all:
	@printf "$(CYAN)>>> Making $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) $(FT_DIR)/$(FT)
	@printf "$(CYAN)>>> Making $(ASM) <<<\n$(RESET)"
	@$(MAKE) $(ASM)
	@printf "$(CYAN)>>> Making $(CRW) <<<\n$(RESET)"
	@$(MAKE) $(CRW)

# **************************************************************************** #

$(FT_DIR)/$(FT):
	@make -C $(FT_DIR)

# **************************************************************************** #

$(ASM): $(ASM_OBJ) $(FT_DIR)/$(FT)
	@printf "$(GREEN)"
	$(CC) $(LDFLAGS) $(LDLIBS) $(ASM_OBJ) -o $@
	@printf "$(RESET)"

$(OBJ_DIR)/$(ASM_DIR):
	@mkdir -p $@

$(OBJ_DIR)/$(ASM_DIR)/%.o: $(SRC_DIR)/$(ASM_DIR)/%.c | $(OBJ_DIR)/$(ASM_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

include $(wildcard $(OBJ_DIR)/$(ASM_DEP))

# **************************************************************************** #

$(CRW): $(CRW_OBJ) $(FT_DIR)/$(FT)
	@printf "$(GREEN)"
	$(CC) $(LDFLAGS) $(LDLIBS) $(CRW_OBJ) -o $@
	@printf "$(RESET)"

$(OBJ_DIR)/$(CRW_DIR):
	@mkdir -p $@

$(OBJ_DIR)/$(CRW_DIR)/%.o: $(SRC_DIR)/$(CRW_DIR)/%.c | $(OBJ_DIR)/$(CRW_DIR)
	@printf "$(MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RESET)"

include $(wildcard $(OBJ_DIR)/$(CRW_DEP))

# **************************************************************************** #

clean:
	@printf "$(CYAN)>>> Cleaning $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR) clean
	@printf "$(CYAN)>>> Cleaning $(ASM) and $(CRW) <<<\n$(RESET)"
	@printf "$(RED)"
	rm -rf $(OBJ_DIR)
	@printf "$(RESET)"

fclean: clean
	@printf "$(CYAN)>>> Purging $(FT_DIR) <<<\n$(RESET)"
	@$(MAKE) -C $(FT_DIR) fclean
	@printf "$(CYAN)>>> Purging $(ASM) and $(CRW) <<<\n$(RESET)"
	@printf "$(RED)"
	rm -f $(ASM) $(CRW)
	@printf "$(RESET)"

re: fclean all
