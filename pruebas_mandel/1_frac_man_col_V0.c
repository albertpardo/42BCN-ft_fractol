/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_frac_man_col_V0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:12:15 by apardo-m          #+#    #+#             */
/*   Updated: 2023/08/28 20:28:50 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#pushing-images-to-a-window
 *
 * Mandelbrot : http://warp.povusers.org/Mandelbrot/
 * 
 */

#include "fractol1V0.h"

int	main(void)
{
	t_imgdata	img;
	t_mlxdata	win;

	win = start_newindow(MAX_X, MAX_Y, "Basic Mandelbrot");
	if (win.mlx_ptr != NULL && win.win_ptr != NULL)
	{
		img = start_newimage(win, 0x007F7F7F);
		if (img.img != NULL)
		{
			basic_mandel(MAX_ITER, &img);
			mlx_key_hook(win.win_ptr, deal_key, &img);
			mlx_hook(win.win_ptr, X_RED, 1L << 0, exit_x, &win);
			mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, img.img, 0, 0);
			mlx_loop(win.mlx_ptr);
		}
	}
	free(win.win_ptr);
	free(win.mlx_ptr);
	return (0);
}
