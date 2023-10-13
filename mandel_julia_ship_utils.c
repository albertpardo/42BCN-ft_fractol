/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia_ship_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:26:21 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/13 19:35:58 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mandel_julia_ship.h"
#include "mandel_julia_ship_zoom_utils.h"

static double	getfactor( double max, double min, int reference)
{
	return ((max - min) / reference);
}

static t_complexnum	getfactor_numcplx(t_mandel_data *dt, t_imgdata *img)
{
	t_complexnum	cn;

	cn.re = getfactor(dt->maxre, dt->minre, img->width);
	cn.im = getfactor(dt->maxim, dt->minim, img->height);
	return (cn);
}

t_mandel_data	getmandelinitdata(t_imgdata *img)
{
	t_mandel_data	dt;

	printf("fractol = %d\n", img->fractol_set);
	dt.hasbeeninit = 1;
	dt.minre = -2.0;
	dt.maxre = 2.0;
	dt.minim = 2.0;
	dt.maxim = -2.0;
	dt.factor_ncmplx = getfactor_numcplx(&dt, img);
	return (dt);
}

void	setmandelnewdata(t_mandel_data *data, t_imgdata *img)
{
	if (img->x_mouse != 0 || img->y_mouse != 0)
		mandelzoom(data, img);
	else
	{
		data->minre += (data->maxre - data->minre) / img->width * img->x_move;
		data->maxre += (data->maxre - data->minre) / img->width * img->x_move;
		data->minim += (data->minim - data->maxim) / img->height * img->y_move;
		data->maxim += (data->minim - data->maxim) / img->height * img->y_move;
		data->factor_ncmplx = getfactor_numcplx(data, img);
		img->x_move = 0.0;
		img->y_move = 0.0;
	}
}
