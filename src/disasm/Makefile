SRC = disasm.c \
      main.c \
	  utils.c

SRC_DIR = src

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.d))

CC = clang

INC_DIR = . include ../libft/include

CFLAGS += -Wall -Wextra -Werror \
          -MD \
		  $(addprefix -I , $(INC_DIR))

LDFLAGS += -L ../libft

LDLIBS += -lft

NAME = dis

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

include $(wildcard $(DEP))

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
