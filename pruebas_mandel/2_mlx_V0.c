/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_mlx_V0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:32:55 by apardo-m          #+#    #+#             */
/*   Updated: 2023/08/30 15:06:14 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol2V0.h"

void	my_mlx_pixel_put(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	exit_x(t_winimg *winimg)
{
	mlx_destroy_image(winimg->win->mlx_ptr, winimg->img->img);
	mlx_destroy_window(winimg->win->mlx_ptr, winimg->win->win_ptr);
	exit (0);
	return (0);
}

int	deal_key(int key, t_winimg *winimg)
{
	if (key == ESC_KEY)
		exit_x(winimg);
	if (key == RIGHT_KEY || key == LEFT_KEY || key == UP_KEY || key == DOWN_KEY)
	{
		if (key == RIGHT_KEY)
			winimg->img->x_move = MOVE_VAL;
		else if (key == LEFT_KEY)
			winimg->img->x_move = -MOVE_VAL;
		else if (key == UP_KEY)
			winimg->img->y_move = MOVE_VAL;
		else if (key == DOWN_KEY)
			winimg->img->y_move = -MOVE_VAL;
		basic_mandel(MAX_ITER, winimg->img);
		mlx_clear_window(winimg->win->mlx_ptr, winimg->win->win_ptr);
		mlx_put_image_to_window(winimg->win->mlx_ptr, \
			winimg->win->win_ptr, winimg->img->img, 0, 0);
	}
	return (0);
}

t_mlxdata	start_newindow(int w, int h, char *str)
{
	t_mlxdata	mlx;

	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr != NULL)
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, w, h, str);
	else
		mlx.win_ptr = NULL;
	mlx.height = h;
	mlx.width = w;
	return (mlx);
}

t_imgdata	start_newimage(t_mlxdata win)
{
	t_imgdata	img;

	img.img = mlx_new_image(win.mlx_ptr, win.width, win.height);
	if (img.img != NULL)
	{
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
		img.height = win.height;
		img.width = win.width;
		img.x_move = 0;
		img.y_move = 0;
	}
	return (img);
}
