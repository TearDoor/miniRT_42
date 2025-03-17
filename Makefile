NAME = miniRT 

OBJ_DIR = ./objs/
PARSING_DIR = ./parsing/

FILE = main
PARSING_FILES = parse utils parse_shape free handle_mlx

OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILE)))
OBJS	+= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(PARSING_FILES)))

CC		= cc
CFLAGS	= -Iinclude
CFLAGS	+= -Wall -Wextra -g3 -fsanitize=address
RM		= rm -rf

# libft
LFT_DIR	= ./libft_42
LIBFT	= $(LFT_DIR)/libft.a

# mlx
MLX_DIR = ./mlx_linux
MLX		= $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(MLX) -lXext -lX11 -lm 

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -Imlx_linux -O3

$(OBJ_DIR)%.o: $(PARSING_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -Imlx_linux -O3

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	@$(RM) $(OBJ_DIR) 

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LFT_DIR) clean
	@make -C $(MLX_DIR) clean

re: fclean all

.phony: all clean fclean re
