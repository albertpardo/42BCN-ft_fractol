# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 10:52:23 by apardo-m          #+#    #+#              #
#    Updated: 2023/09/24 10:58:22 by apardo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_OPENGL = ./minilibx_opengl_20191021
MLX = $(MLX_OPENGL)

NAME = fractol
SRC = $(NAME).c \
	  cli_utils.c

HEADER = cli.h
OBJS = $(SRC:%.c=%.o)

NAMES_BONUS = fractol_bonus
SRC_BONUS = $(NAME_BONUS).c
HEADER_BONUS = cli.h

FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

all: $(NAME)

$(NAME): $(LIBF) $(OBJS)
	cc $(FLAGS) $(LIBFT) $(OBJS) -o $(NAME)


%.o: %.c Makefile $(HEADER)
	cc $(FLAGS) -c $< -o $@

julia0:
	make -C $(MLX)
	gcc $(FLAGS)  -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 5_frac_movzoom_color_V0.c 5_colors_V0.c 5_mlx_V0.c 5_event_hook_V0.c 5_julia_V0.c 5_julia_utils_V0.c

bonus: $(NAME_BONUS)

$(NAME_BONUS): Makefile $(HEADER_BONUS) $(LIBFT)
	cc $(FLAGS) $(SRC_SERV_BONUS) $(LIBFT) -o $(NAME_SERV_BONUS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make --no-print-directory clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean: clean
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@echo "--> Remove files : $(NAME) $(NAME_BONUS)"
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
