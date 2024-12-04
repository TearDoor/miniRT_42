NAME	= libtuples.a

SRC		= tuple_basic.c tuple_arith.c tuple_advanced.c \
			utils.c
OBJ_DIR	= objs
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC		= gcc
CFLAGS	= -I./include
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
			ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
			mkdir $@

clean:
			$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.phony: all clean fclean re

