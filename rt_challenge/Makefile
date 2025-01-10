NAME	=	raytrace

vpath %.c	srcs tests srcs/minilibx srcs/objects srcs/raytracing

SRC		=	main.c simple_utils.c \
			cannon.c my_first_sphere.c scene1.c \
			objects.c sphere.c plane.c cylinder.c cone.c \
			color_at.c light.c lighting.c shadows.c \
			rays.c intersect.c world.c camera.c \
			mlx_showimage.c

OBJ_DIR	= objs
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# tuples library
UTIL_DIR	= ./utils
LIBUTIL	= $(UTIL_DIR)/libutils.a

# libft
LFT_DIR	= ./libft_42
LIBFT	= $(LFT_DIR)/libft.a

CC		= cc
CFLAGS	= -Iinclude -I$(UTIL_DIR) -I$(LFT_DIR)
CFLAGS	+= -Wall -Wextra
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
			@make -C $(LFT_DIR)

clean:
			$(RM) $(OBJ_DIR)
			make fclean -C $(UTIL_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.phony: all clean fclean re

