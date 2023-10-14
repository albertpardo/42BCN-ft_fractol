/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:21:50 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/14 21:52:14 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_X 500
# define MAX_Y 500
# define MOVE_VAL 20
# define ZOOM_VAL 2.0

# define ESC_KEY 53
# define UP_KEY	126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123

# define ONE 83
# define TWO 84
# define THREE 85
# define FOUR 86
# define FIVE 87
# define SIX 88
# define SEVEN 89

# define ONE_NUM 18
# define TWO_NUM 19
# define THREE_NUM 20
# define FOUR_NUM  21
# define FIVE_NUM 23
# define SIX_NUM 22
# define SEVEN_NUM 26

# define X_RED 17

# define ZOOM_IN_BUTTON	5
# define ZOOM_OUT_BUTTON 4

# define MAX_ITER 1000
# define MAX_PALETES 7
# define DEFAULT_PALETE 1

# define MANDEL_SET 1
# define JULIA_SET 2
# define SHIP_SET 3

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
	double	zoom;
	int		x_mouse;
	int		y_mouse;
	int		act_plte;
	int		fractol_set;
	double	julia_re;
	double	julia_img;
}				t_imgdata;

typedef struct s_winimg
{
	t_mlxdata	*win;
	t_imgdata	*img;
}				t_winimg;

// colors.c
int			setcolor(int actv_pal, int n, const int maxiter);

// set_mandel_julia_ship.c
void		set_mandel_julia_ship(int MaxIteration, t_imgdata *img);

// using_mlx.c
void		my_put_pixel(t_imgdata *data, int x, int y, int color);
t_mlxdata	start_newindow(int w, int h, char *str);
t_imgdata	start_newimage(t_mlxdata win);

//event_exit_mouse.c
int			exit_x(t_winimg *winimg);
int			mouse_event(int button, int x, int y, t_winimg *winimg);

//event_key.c
int			deal_key(int key, t_winimg *winimg);

// mandel_julia_ship.c
void		mandel_julia_ship(int fractol_set, double jul_re, double jul_im);

#endif
