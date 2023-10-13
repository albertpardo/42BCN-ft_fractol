/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia_ship_zoom_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:26:56 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/13 19:36:20 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mandel_julia_ship.h"

static double	getk(double zoomfactor, int w, int pos)
{
	return ((1 - zoomfactor) * pos / w);
}

static double	getlowlimit(double k, double up, double low)
{
	return (k * (up - low) + low);
}

static double	getuplimit( double lowlimit, double zoomfactor, double up, \
		double low)
{
	return (lowlimit + ((up - low) * zoomfactor));
}

static t_complexnum	getcnmouse(t_mandel_data *data, t_imgdata *img)
{
	t_complexnum	cn;

	cn.re = (data->maxre - data->minre) / img->width * img->x_mouse + \
			data->minre;
	cn.im = (data->minim - data->maxim) / img->height * img->y_mouse + \
			data->maxim;
	return (cn);
}

void	mandelzoom(t_mandel_data *data, t_imgdata *img)
{
	t_complexnum	c_mpos;
	double			oldmin;
	double			oldmax;
	double			k;

	c_mpos = getcnmouse(data, img);
	oldmin = data->minre;
	oldmax = data->maxre;
	k = getk(img->zoom, img->width, img->x_mouse);
	data->minre = getlowlimit(k, oldmax, oldmin);
	data->maxre = getuplimit(data->minre, img->zoom, oldmax, oldmin);
	oldmin = data->minim;
	oldmax = data->maxim;
	k = getk(img->zoom, img->height, img->y_mouse);
	data->maxim = getlowlimit(k, oldmin, oldmax);
	data->minim = getuplimit(data->maxim, img->zoom, oldmin, oldmax);
	c_mpos = getcnmouse(data, img);
	img->x_mouse = 0;
	img->y_mouse = 0;
}
