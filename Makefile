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

SRC_DIR := src

# **************************************************************************** #

ASM_DIR := asm

ASM_SRC := analize_lex.c \
           analize_order.c \
           convert.c \
           convert_token.c \
           error_manager.c \
           free_things.c \
           header_pars.c \
           init_info.c \
           main.c \
           operation.c \
           reading_proc.c \
           split_tok.c \
           utils.c \
           utils2.c \
           utils3.c \
           verify_things.c

ASM_SRC := $(addprefix $(ASM_DIR)/, $(ASM_SRC))
ASM_OBJ := $(ASM_SRC:.c=.o)
ASM_DEP := $(ASM_SRC:.c=.d)

# **************************************************************************** #

CRW_DIR := corewar

CRW_SRC := args.c \
           carriage.c \
           check_op.c \
           cop.c \
           display_arena.c \
           end_cw.c \
           init_cw.c \
           init_players.c \
           init_session.c \
           main.c \
           op_add.c \
           op_aff.c \
           op_and.c \
           op_fork.c \
           op_ld.c \
           op_ldi.c \
           op_lfork.c \
           op_live.c \
           op_lld.c \
           op_lldi.c \
           op_or.c \
           op_st.c \
           op_sti.c \
           op_sub.c \
           op_xor.c \
           op_zjmp.c \
           ops.c \
           parse_players.c \
           play_cw.c \
           utils.c \
           utils_int.c

CRW_SRC := $(addprefix $(CRW_DIR)/, $(CRW_SRC))
CRW_OBJ := $(CRW_SRC:.c=.o)
CRW_DEP := $(CRW_SRC:.c=.d)

# **************************************************************************** #

FT_DIR := libft

FT := libft.a

# **************************************************************************** #

INC_DIR := include \
           $(FT_DIR)

# **************************************************************************** #

OBJ_DIR := obj

ASM_OBJ := $(addprefix $(OBJ_DIR)/, $(ASM_OBJ))
ASM_DEP := $(addprefix $(OBJ_DIR)/, $(ASM_DEP))

CRW_OBJ := $(addprefix $(OBJ_DIR)/, $(CRW_OBJ))
CRW_DEP := $(addprefix $(OBJ_DIR)/, $(CRW_DEP))

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
	$(CC) $(ASM_OBJ) $(LDFLAGS) $(LDLIBS) -o $@
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
	$(CC) $(CRW_OBJ) $(LDFLAGS) $(LDLIBS) -o $@
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
