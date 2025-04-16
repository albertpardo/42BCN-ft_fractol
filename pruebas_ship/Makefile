FLAGS = -Wall -Wextra -Werror
MLX_OPENGL = ./minilibx_opengl_20191021
MLX = $(MLX_OPENGL)

.PHONY: all

all:
	@echo "call the rigth test"

ship0:
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 5_colors_V0.c 5_mlx_V0.c 6_event_hook_V0.c 6_ship_main_V0.c 6_ship_V0.c 6_ship_utils_V0.c

