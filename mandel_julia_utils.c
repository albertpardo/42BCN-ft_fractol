/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:53:33 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/12 09:11:10 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mandel_julia.h"
#include "mandel_julia_zoom_utils.h"

static double	getfactor( double max, double min, int reference)
{
	return ((max - min) / reference);
}

static double	maxvalue(double xtrm, t_mandel_data *dt, t_imgdata *img)
{
	return (xtrm + img->height * getfactor(dt->maxre, dt->minre, img->width));
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
	if (img->fractol_set == MANDEL_SET)
	{
		dt.maxre = 1.0;
		dt.minim = -1.5;
	}
	else
	{
		dt.maxre = 2.0;
		dt.minim = -2.0;
	}
	dt.maxim = maxvalue(dt.minim, &dt, img);
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
