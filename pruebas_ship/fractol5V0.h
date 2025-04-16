/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol5V0.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:43:35 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/13 15:38:24 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL5V0_H
# define FRACTOL5V0_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_X 800
# define MAX_Y 800
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
}				t_imgdata;

typedef struct s_winimg
{
	t_mlxdata	*win;
	t_imgdata	*img;
}				t_winimg;

// 5_colorsV0.c
int			setcolor(int actv_pal, int n, const int maxiter);

// 6_ship_V0.c
void		basic_ship(int MaxIteration, t_imgdata *img);

//5_mlx_V0.c
void		my_put_pixel(t_imgdata *data, int x, int y, int color);
t_mlxdata	start_newindow(int w, int h, char *str);
t_imgdata	start_newimage(t_mlxdata win);

//5_event_hook_V0.c
int			exit_x(t_winimg *winimg);
int			deal_key(int key, t_winimg *winimg);
int			mouse_event(int button, int x, int y, t_winimg *winimg);
#endif
