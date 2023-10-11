/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:01:48 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/11 12:13:30 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandel_julia(int fractol_set , double julia_re, double julia_im)
{
	t_imgdata	img;
	t_mlxdata	win;
	t_winimg	winimg;

	if (fractol_set == MANDEL_SET)
		win = start_newindow(MAX_X, MAX_Y, "Colors Mandelbrot");
	else if(fractol_set == JULIA_SET)
		win = start_newindow(MAX_X, MAX_Y, "Colors Julia");
	else
		return;
	if (win.mlx_ptr != NULL && win.win_ptr != NULL)
	{
		img = start_newimage(win);
		if (img.img != NULL)
		{
			img.fractol_set = fractol_set;
			img.julia_re = julia_re;
			img.julia_img = julia_im;
			printf("(Madel Julia) palete = %d\n", img.act_plte);
			winimg.win = &win;
			winimg.img = &img;
			mlx_key_hook(winimg.win->win_ptr, deal_key, &winimg);
			mlx_hook(winimg.win->win_ptr, X_RED, 1L << 0, exit_x, &winimg);
			mlx_mouse_hook(win.win_ptr, mouse_event, &winimg);
			set_mandel_julia(MAX_ITER, winimg.img);
			mlx_put_image_to_window(winimg.win->mlx_ptr, winimg.win->win_ptr, \
					winimg.img->img, 0, 0);
			mlx_loop(winimg.win->mlx_ptr);
		}
	}
	free(winimg.win->win_ptr);
	free(winimg.win->mlx_ptr);
}
