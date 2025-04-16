/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:25:20 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/14 23:18:27 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./libft/ft_printf.h"

static void	startwindow(t_winimg	*winimg)
{
	mlx_key_hook(winimg->win->win_ptr, deal_key, winimg);
	mlx_hook(winimg->win->win_ptr, X_RED, 1L << 0, exit_x, winimg);
	mlx_mouse_hook(winimg->win->win_ptr, mouse_event, winimg);
	set_mandel_julia_ship(MAX_ITER, winimg->img);
	mlx_put_image_to_window(winimg->win->mlx_ptr, winimg->win->win_ptr, \
			winimg->img->img, 0, 0);
	mlx_loop(winimg->win->mlx_ptr);
}

void	setwindow(int fractol_set, t_mlxdata	*win)
{
	if (fractol_set == MANDEL_SET)
		*win = start_newindow(MAX_X, MAX_Y, "Mandelbrot");
	else if (fractol_set == JULIA_SET)
		*win = start_newindow(MAX_X, MAX_Y, "Julia");
	else if (fractol_set == SHIP_SET)
		*win = start_newindow(MAX_X, MAX_Y, "Burningship");
}

void	mandel_julia_ship(int fractol_set, double jul_re, double jul_im)
{
	t_imgdata	img;
	t_mlxdata	win;
	t_winimg	winimg;

	setwindow(fractol_set, &win);
	if (win.mlx_ptr != NULL && win.win_ptr != NULL)
	{
		img = start_newimage(win);
		if (img.img != NULL)
		{
			img.fractol_set = fractol_set;
			img.julia_re = jul_re;
			img.julia_img = jul_im;
			winimg.win = &win;
			winimg.img = &img;
			startwindow(&winimg);
		}
		free(win.win_ptr);
		free(win.mlx_ptr);
	}
	if (win.mlx_ptr == NULL || win.win_ptr == NULL || img.img == NULL)
	{
		ft_printf("MEMORY PROBLEMS!!");
		exit(1);
	}
}
