FLAGS = -Wall -Wextra -Werror
MLX_OPENGL = ./minilibx_opengl_20191021
MLX = $(MLX_OPENGL)

LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))


.PHONY: all

all:
	@echo "call the rigth test"

julia0:
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 5_frac_movzoom_color_V0.c 5_colors_V0.c 5_mlx_V0.c 5_event_hook_V0.c 5_julia_V0.c 5_julia_utils_V0.c

cli0:
	gcc test_cli_V0.c -o fractol

cli1:
	gcc test_cli_V1.c -o fractol

cli2:
	gcc test_cli_V2.c cli_utils_V0.c -o fractol

cli3: Makefile $(LIBFT)
	cc $(FLAGS) $(LIBFT) test_cli_V3.c cli_utils_V0.c -o fractol

$(LIBFT):
	@make -C $(LIBFT_DIR)
