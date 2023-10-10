/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:36:07 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/10 17:24:02 by apardo-m         ###   ########.fr       */
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

/* TODO Diferenciate Mandel vs Julia */
static void	refresh_img(t_winimg *winimg)
{
	set_mandel_julia(MAX_ITER, winimg->img); //Here Julia
	mlx_clear_window(winimg->win->mlx_ptr, winimg->win->win_ptr);
	mlx_put_image_to_window(winimg->win->mlx_ptr, \
		winimg->win->win_ptr, winimg->img->img, 0, 0);
}

static void	set_intvalue_refresh_img(int *var, int val, t_winimg *winimg)
{
	*var = val;
	refresh_img(winimg);
}

static void	set_doubvalue_refresh_img(double *var, double val, t_winimg *winimg)
{
	*var = val;
	refresh_img(winimg);
}

int	deal_key(int key, t_winimg *winimg)
{
	if (key == ESC_KEY)
		exit_x(winimg);
	if (key == LEFT_KEY)
		set_doubvalue_refresh_img(&winimg->img->x_move, -MOVE_VAL, winimg);
	else if (key == RIGHT_KEY)
		set_doubvalue_refresh_img(&winimg->img->x_move, MOVE_VAL, winimg);
	else if (key == DOWN_KEY)
		set_doubvalue_refresh_img(&winimg->img->y_move, MOVE_VAL, winimg);
	else if (key == UP_KEY)
		set_doubvalue_refresh_img(&winimg->img->y_move, -MOVE_VAL, winimg);
	else if (key == ONE || key == ONE_NUM)
		set_intvalue_refresh_img(&winimg->img->act_plte, 1, winimg);
	else if (key == TWO || key == TWO_NUM)
		set_intvalue_refresh_img(&winimg->img->act_plte, 2, winimg);
	else if (key == THREE || key == THREE_NUM)
		set_intvalue_refresh_img(&winimg->img->act_plte, 3, winimg);
	else if (key == FOUR || key == FOUR_NUM)
		set_intvalue_refresh_img(&winimg->img->act_plte, 4, winimg);
	else if (key == FIVE || key == FIVE_NUM)
		set_intvalue_refresh_img(&winimg->img->act_plte, 5, winimg);
	else if (key == SIX || key == SIX_NUM)
		set_intvalue_refresh_img(&winimg->img->act_plte, 6, winimg);
	else if (key == SEVEN || key == SEVEN_NUM)
		set_intvalue_refresh_img(&winimg->img->act_plte, 7, winimg);
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
