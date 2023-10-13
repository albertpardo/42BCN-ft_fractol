# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 10:52:23 by apardo-m          #+#    #+#              #
#    Updated: 2023/10/13 19:21:34 by apardo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_OPENGL = ./minilibx_opengl_20191021
MLX = $(MLX_OPENGL)

NAME = fractol
SRC = $(NAME).c \
		cli_utils.c \
		colors.c \
		event_exit_mouse.c \
		event_key.c \
		mandel_julia_ship.c \
		mandel_julia_ship_utils.c \
		mandel_julia_ship_zoom_utils.c \
		using_mlx.c \
		set_mandel_julia_ship.c

HEADERS = cli.h \
		 fractol.h \
		 mandel_julia_ship.h \
		 mandel_julia_ship_zoom_utils.h

OBJS = $(SRC:%.c=%.o)

NAMES_BONUS = fractol_bonus
SRC_BONUS = $(NAME_BONUS).c
HEADER_BONUS = cli.h

FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

all: 
	@Make --no-print-directory libs
	@make -C $(MLX)
	@Make --no-print-directory $(NAME)


$(NAME): $(LIBFT) $(OBJS) 
	cc $(FLAGS)  -L $(MLX) -l mlx -framework OpenGL -framework AppKit $(LIBFT) $(OBJS) -o $(NAME)

%.o: %.c Makefile $(HEADERS)
	cc $(FLAGS) -I $(MLX) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): Makefile $(HEADER_BONUS) $(LIBFT)
	cc $(FLAGS) $(SRC_BONUS) $(LIBFT) -o $(NAME_BONUS)

libs:
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@make --no-print-directory clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean: clean
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@echo "--> Remove files : $(NAME) $(NAME_BONUS) mandel"
	rm -f $(NAME) $(NAME_BONUS) mandel

re: fclean all

.PHONY: all clean fclean re bonus
