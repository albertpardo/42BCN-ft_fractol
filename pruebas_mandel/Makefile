FLAGS = -Wall -Wextra -Werror
MLX_OPENGL = ./minilibx_opengl_20191021
MLX = $(MLX_OPENGL)

.PHONY: all

all:
	@echo "call the rigth test"

0mandel: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 0_basic_mandelbrot_colors.c

v0mandel: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 1_frac_man_col_V0.c 1_colors_V0.c 1_mlx_V0.c 1_mandel_V0.c

2_man_move: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 2_frac_man_col_V0.c 1_colors_V0.c 2_mlx_V0.c 2_mandel_V0.c

2_man_move1: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 2_frac_man_col_V0.c 1_colors_V0.c 2_mlx_V0.c 2_mandel_V1.c

3_zoom1: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 3_frac_man_zoom_V0.c 1_colors_V0.c 3_mlx_V0.c 3_event_hook_V0.c 3_mandel_V0.c 3_mandel_utils_V0.c

3_zoom2: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 3_frac_man_zoom_V0.c 1_colors_V0.c 3_mlx_V0.c 3_event_hook_V0.c 3_mandel_V0.c 3_mandel_utils_V1.c

4_colors1: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 4_frac_movzoom_color_V0.c 4_colors_V0.c 4_mlx_V0.c 4_event_hook_V0.c 4_mandel_V0.c 4_mandel_utils_V0.c

4_colors2: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 4_frac_movzoom_color_V1.c 4_colors_V1.c 4_mlx_V1.c 4_event_hook_V1.c 4_mandel_V1.c 4_mandel_utils_V1.c

4_colors3: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 4_frac_movzoom_color_V2.c 4_colors_V1.c 4_mlx_V2.c 4_event_hook_V2.c 4_mandel_V2.c 4_mandel_utils_V2.c
