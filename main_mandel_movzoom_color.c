/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandel_movzoom_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:01:48 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/09 13:02:00 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_imgdata	img;
	t_mlxdata	win;
	t_winimg	winimg;

	win = start_newindow(MAX_X, MAX_Y, "Colors Mandelbrot");
	if (win.mlx_ptr != NULL && win.win_ptr != NULL)
	{
		img = start_newimage(win);
		if (img.img != NULL)
		{
			printf("(main) palete = %d\n", img.act_plte);
			winimg.win = &win;
			winimg.img = &img;
			mlx_key_hook(winimg.win->win_ptr, deal_key, &winimg);
		//	mlx_hook(winimg.win->win_ptr, X_RED, 1L << 0, exit_x, &winimg);
			mlx_hook(winimg.win->win_ptr, X_RED, 1L << 0, exit_x, &winimg);
			mlx_mouse_hook(win.win_ptr, mouse_event, &winimg);
			basic_mandel(MAX_ITER, winimg.img);
			mlx_put_image_to_window(winimg.win->mlx_ptr, winimg.win->win_ptr, \
					winimg.img->img, 0, 0);
			mlx_loop(winimg.win->mlx_ptr);
		}
	}
	free(winimg.win->win_ptr);
	free(winimg.win->mlx_ptr);
	return (0);
}
