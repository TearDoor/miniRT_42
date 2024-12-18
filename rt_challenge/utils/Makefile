NAME	= libutils.a

SRC		= tuple_basic.c tuple_arith.c tuple_advanced.c \
		  colors.c color_operations.c \
		  canvas.c canvas_to_ppm.c \
		  matrix.c matrix_mult.c matrix_invert.c matrix_invert_utils.c \
		  transformation_matrices.c rotation_matrices.c \
		  utils.c

OBJ_DIR	= objs
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# libft
LFT_DIR	= ../libft_42
LIBFT	= $(LFT_DIR)/libft.a

CC		= gcc
CFLAGS	= -I$(LFT_DIR)
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
			@ar rcs $@ $^
			@echo "Utils library compile complete."

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(LIBFT)
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
			@mkdir $@

$(LIBFT):
			@make -C $(LFT_DIR)

clean:
			$(RM) $(OBJ_DIR)
			make fclean -C $(LFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.phony: all clean fclean re

