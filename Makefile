NAME	=	miniRT

vpath %.c	srcs tests srcs/minilibx srcs/objects srcs/raytracing srcs/patterns srcs/parsing

SRC		=	main.c simple_utils.c init_rt.c \
			parse.c parse_shape.c parse_utils.c parse_utils2.c free.c load_parse.c \
			color_at.c light.c lighting.c shadows.c \
			rays.c intersect.c intersect_utils.c world.c camera.c render.c \
			mlx_showimage.c keys.c  key_utils.c mouse_control.c mouse_utils.c
SRC		+=	objects.c sphere.c plane.c cylinder.c cone.c 
SRC		+=	pattern.c stripes.c gradient.c rings.c checkers.c \
			uv_pattern.c uv_checkers.c uv_image.c normalmap.c \
			mappings.c

# test scenes
SRC		+=	cannon.c scene1.c earth.c leak_test.c mapping_test.c

OBJ_DIR	= objs
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# tuples library
UTIL_DIR	= ./utils
LIBUTIL	= $(UTIL_DIR)/libutils.a

# libft
LFT_DIR	= ./libft_42
LIBFT	= $(LFT_DIR)/libft.a

CC		=	cc
CFLAGS	=	-Iinclude -I$(UTIL_DIR) -I$(LFT_DIR)
CsFLAGS	+=	-Wall -Wextra
RM		=	rm -rf

all: $(NAME)

$(NAME): $(OBJS) | $(LIBUTIL) $(LIBFT)
			@$(CC) $(CFLAGS) -o $@ $^ $(LIBUTIL) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
			@echo "miniRT compiled             "

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
			@printf "\rCompiling %s            " $@
			@$(CC) $(CFLAGS) -c $< -o $@ -Imlx_linux
			@printf "\r"

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

# only remakes the main raytracing code without touching libft and libutils
cleancore:
			$(RM) $(OBJ_DIR)
			$(RM) $(NAME)

recore: cleancore all

.phony: all clean fclean re cleancore recore

