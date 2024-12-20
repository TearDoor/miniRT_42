NAME	=	raytrace

SRC		=	main.c \
			cannon.c my_first_sphere.c \
			rays.c intersect.c light.c

OBJ_DIR	= objs
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# tuples library
UTIL_DIR	= ./utils
LIBUTIL	= $(UTIL_DIR)/libutils.a

# libft
LFT_DIR	= ./libft_42
LIBFT	= $(LFT_DIR)/libft.a

CC		= gcc
CFLAGS	= -Iinclude -I$(UTIL_DIR) -I$(LFT_DIR)
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS) | $(LIBUTIL) $(LIBFT)
			$(CC) $(CFLAGS) -o $@ $^ $(LIBUTIL) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@ -Imlx_linux -O3

$(OBJ_DIR):
			@mkdir $@

$(LIBUTIL):
			@echo "utils for minirt not found. Creating..."
			@make -C $(UTIL_DIR)

$(LIBFT):
			@echo "libft not found. Creating..."
			@make -C $(LFT_DIR)

clean:
			$(RM) $(OBJ_DIR)
			make fclean -C $(UTIL_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.phony: all clean fclean re

