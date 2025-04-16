/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2V0.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:30:20 by apardo-m          #+#    #+#             */
/*   Updated: 2023/08/29 11:35:43 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL2V0_H
# define FRACTOL2V0_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_X 500
# define MAX_Y 500
# define MOVE_VAL 20
# define ESC_KEY 53
# define UP_KEY	126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define X_RED 17
# define MAX_ITER 60

typedef struct mlxdata
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}				t_mlxdata;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	x_move;
	double	y_move;
}				t_imgdata;

typedef struct s_winimg
{
	t_mlxdata	*win;
	t_imgdata	*img;
}				t_winimg;

// 1_colorsV0.c
int			setcolor(int n, const int maxiter);

// 1_mandel_V0.c
void		basic_mandel(int MaxIteration, t_imgdata *img);

//1_mlx_V0.c
void		my_mlx_pixel_put(t_imgdata *data, int x, int y, int color);
int			deal_key(int key, t_winimg *winimg);
int			exit_x(t_winimg *winimg);
t_mlxdata	start_newindow(int w, int h, char *str);
t_imgdata	start_newimage(t_mlxdata win);
#endif
