/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ship_utils_V0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:47:50 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/13 18:06:36 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Based 5_julia_utils_V0.c */

#include "fractol5V0.h"
#include "julia5V0.h"

static double	getfactor( double max, double min, int reference)
{
	return ((max - min) / reference);
}

/*
static double	maxValue(double xtrm, t_mandel_data *dt, t_imgdata *img)
{
	return(xtrm + img->height * getfactor(dt->maxre, dt->minre, img->width));
}
*/

static t_complexnum	getfactor_numcplx(t_mandel_data *dt, t_imgdata *img)
{
	t_complexnum	cn;

 	cn.re = getfactor(dt->maxre, dt->minre, img->width);
	cn.im = getfactor(dt->maxim, dt->minim, img->height);
	return (cn);
}

static t_complexnum	getcnmouse(t_mandel_data *data, t_imgdata *img)
{
	t_complexnum	cn;

	cn.re = (data->maxre - data->minre) / img->width * img->x_mouse + data->minre;
	cn.im = (data->minim  - data->maxim) / img->height * img->y_mouse + data->maxim;
	return (cn);
}

static double getlowlimit(double zoomfactor, double up, double low, int w, int pos)
{
	return ((1 - zoomfactor) * (up - low) / w * pos + low);
}

static double getuplimit( double lowlimit, double zoomfactor, double up, double low)
{
	return (lowlimit + ((up - low) * zoomfactor));
}

static void	mandelzoom(t_mandel_data *data, t_imgdata *img)
{
	t_complexnum	c_mpos;
	double			oldmin;
	double			oldmax;

	c_mpos = getcnmouse(data, img);
//	printf("------------------------\n");
//	printf("Antes   : (%d,%d) . (%f,j%f) [(%f,%f), j(%f,%f)]\n", img->x_mouse, img->y_mouse, c_mpos.re, c_mpos.im, data->minre, data->maxre, data->maxim, data->minim);

	oldmin = data->minre;
	oldmax = data->maxre;
	data->minre = getlowlimit(img->zoom, oldmax, oldmin, img->width, img->x_mouse);
	data->maxre = getuplimit(data->minre, img->zoom, oldmax, oldmin);
	oldmin = data->minim;
	oldmax = data->maxim;
	data->maxim = getlowlimit(img->zoom, oldmin, oldmax, img->height, img->y_mouse);
	data->minim = getuplimit(data->maxim, img->zoom, oldmin, oldmax);

	c_mpos = getcnmouse(data, img);

//	printf("Despues : (%d,%d) . (%f,j%f) [(%f,%f), j(%f,%f)]\n", img->x_mouse, img->y_mouse, c_mpos.re, c_mpos.im, data->minre, data->maxre, data->maxim, data->minim);

	img->x_mouse = 0;
	img->y_mouse = 0;
}

t_mandel_data	getmandelinitdata(t_imgdata *img)
{
	t_mandel_data	dt;

	dt.hasbeeninit = 1;
	dt.minre = -2.0;
	dt.maxre = 1.17;
//	dt.minim = -2.0;
//	dt.maxim = maxValue(dt.minim, &dt, img);
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
		data->minim += (data->minim  - data->maxim) / img->height * img->y_move;
		data->maxim += (data->minim  - data->maxim) / img->height * img->y_move;
		data->factor_ncmplx = getfactor_numcplx(data, img);
		img->x_move = 0.0;
		img->y_move = 0.0;
	}
}
