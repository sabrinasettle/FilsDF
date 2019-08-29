NAME = fdf

SOURCES = main \
	make_env \
	valid_file \
	allocation \
	get_and_store \
	render \

BONUSES = keycontrols \
	mousemovement \
	rotation \
	colors \

MLX_LIB = $(addprefix $(MLX_D),libmlx.a) -lmlx
MLX_D = ./minilibx_macos/

LIBFT = $(addprefix $(LIBFT_D),libft.a) -lft
LIBFT_D = ./libft/

OBJ_DIR = objects

VPATH=includes:sources:libft:minilibx_macos:bonuses
OBJECTS = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SOURCES)))
OBJECTS += $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(BONUSES)))

GCC = gcc
# LLDB/LEAKS = -Wall -Werror -Wextra -g
FLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

INCLUDES = includes/fdf.h

all: $(LIBFT) $(MLX_LIB) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_D)

$(MLX_LIB):
	@make -C $(MLX_D)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:%.c
	@$(GCC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJECTS)
	@$(GCC) -g $(FLAGS) $(OBJECTS) $(INC) -L $(MLX_D) $(MLXFLAGS) -L $(LIBFT_D) -l ft -o $(NAME)
	@echo =====Project made!======

clean:
	@rm -rf $(OBJECTS)
	@make clean -C $(LIBFT_D)
	@echo ====Project cleaned!=====

fclean: clean
	@make fclean -C $(LIBFT_D)
	@make clean -C $(MLX_D)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: make, all, clean, fclean, re
