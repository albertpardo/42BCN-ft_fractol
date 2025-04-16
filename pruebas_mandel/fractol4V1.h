/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol4V1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:14:38 by apardo-m          #+#    #+#             */
/*   Updated: 2023/09/08 12:44:19 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FRACTOL4V1_H
# define FRACTOL4V1_H

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
	int		active_palete;
}				t_imgdata;

typedef struct s_winimg
{
	t_mlxdata	*win;
	t_imgdata	*img;
}				t_winimg;

// 4_colorsV1.c
int			setcolor(int actv_pal, int n, const int maxiter);

// 4_mandel_V0.c
void		basic_mandel(int MaxIteration, t_imgdata *img);

//4_mlx_V0.c
void		my_put_pixel(t_imgdata *data, int x, int y, int color);
t_mlxdata	start_newindow(int w, int h, char *str);
t_imgdata	start_newimage(t_mlxdata win);

//4_event_hook_V0.c
int			exit_x(t_winimg *winimg);
int			deal_key(int key, t_winimg *winimg);
int			mouse_event(int button, int x, int y, t_winimg *winimg);
#endif
