/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_event_hook_V0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:54:37 by apardo-m          #+#    #+#             */
/*   Updated: 2023/09/08 11:04:27 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol4V0.h"

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
		if (key == LEFT_KEY)
			winimg->img->x_move = -MOVE_VAL;
		else if (key == RIGHT_KEY)
			winimg->img->x_move = MOVE_VAL;
		else if (key == DOWN_KEY)
			winimg->img->y_move = MOVE_VAL;
		else if (key == UP_KEY)
			winimg->img->y_move = -MOVE_VAL;
		basic_mandel(MAX_ITER, winimg->img);
		mlx_clear_window(winimg->win->mlx_ptr, winimg->win->win_ptr);
		mlx_put_image_to_window(winimg->win->mlx_ptr, \
			winimg->win->win_ptr, winimg->img->img, 0, 0);
	}
	return (0);
}

int	mouse_event(int button, int x, int y, t_winimg *winimg)
{
	if (button == ZOOM_IN_BUTTON || button == ZOOM_OUT_BUTTON)
	{
		winimg->img->x_mouse = x;
		winimg->img->y_mouse = y;
		if (button == ZOOM_IN_BUTTON)
			winimg->img->zoom = 1.0 / ZOOM_VAL;
		else if (button == ZOOM_OUT_BUTTON)
			winimg->img->zoom = ZOOM_VAL;
		basic_mandel(MAX_ITER, winimg->img);
		mlx_clear_window(winimg->win->mlx_ptr, winimg->win->win_ptr);
		mlx_put_image_to_window(winimg->win->mlx_ptr, \
			winimg->win->win_ptr, winimg->img->img, 0, 0);
	}
	return (0);
}
