/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia_zoom_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:28:27 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/12 09:08:13 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mandel_julia.h"

static double	getlowlimit(double zoomfactor, double up, double low, int w, \
		int pos)
{
	return ((1 - zoomfactor) * (up - low) / w * pos + low);
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

	c_mpos = getcnmouse(data, img);
	oldmin = data->minre;
	oldmax = data->maxre;
	data->minre = getlowlimit(img->zoom, oldmax, oldmin, img->width, \
			img->x_mouse);
	data->maxre = getuplimit(data->minre, img->zoom, oldmax, oldmin);
	oldmin = data->minim;
	oldmax = data->maxim;
	data->maxim = getlowlimit(img->zoom, oldmin, oldmax, img->height, \
			img->y_mouse);
	data->minim = getuplimit(data->maxim, img->zoom, oldmin, oldmax);
	c_mpos = getcnmouse(data, img);
	img->x_mouse = 0;
	img->y_mouse = 0;
}
