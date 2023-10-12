/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:36:07 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/11 14:37:19 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_x(t_winimg *winimg)
{
	mlx_destroy_image(winimg->win->mlx_ptr, winimg->img->img);
	mlx_destroy_window(winimg->win->mlx_ptr, winimg->win->win_ptr);
	exit (0);
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
		set_mandel_julia(MAX_ITER, winimg->img);
		mlx_clear_window(winimg->win->mlx_ptr, winimg->win->win_ptr);
		mlx_put_image_to_window(winimg->win->mlx_ptr, \
			winimg->win->win_ptr, winimg->img->img, 0, 0);
	}
	return (0);
}
