NAME	= raytrace

SRC		= main.c

OBJ_DIR	= objs
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# tuples library
TUP_DIR	= ./tuples
LIBTUP	= $(TUP_DIR)/libtuples.a

# libft
LFT_DIR	= ./libft_42
LIBFT	= $(LFT_DIR)/libft.a

CC		= gcc
CFLAGS	= -Iinclude -I$(TUP_DIR) -I$(LFT_DIR)
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS) | $(LIBTUP) $(LIBFT)
			$(CC) $(CFLAGS) -o $@ $^ $(LIBTUP) $(LIBFT) -lm

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
			mkdir $@

$(LIBTUP):
			make -C $(TUP_DIR)

$(LIBFT):
			make -C $(LFT_DIR)

clean:
			$(RM) $(OBJ_DIR)
			make fclean -C $(TUP_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.phony: all clean fclean re

