/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:33:14 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/09 12:33:20 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_put_pixel(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
		img.zoom = 0.0;
		img.x_mouse = 0;
		img.y_mouse = 0;
		img.act_plte = DEFAULT_PALETE;
		printf("start_newimage() : %d\n", img.act_plte);
	}
	return (img);
}
