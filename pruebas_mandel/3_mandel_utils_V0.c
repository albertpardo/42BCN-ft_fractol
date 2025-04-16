/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_mandel_utils_V0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:17:59 by apardo-m          #+#    #+#             */
/*   Updated: 2023/08/31 14:27:08 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Al hacer Zoom no mantiene la posicion x,y equivalente al numero complejo 
 * donde esta el mouse al hacer el zoom.
 */

#include "fractol3V0.h"
#include "mandel3V0.h"

static double	setfactor( double max, double min, int reference)
{
	return ((max - min) / reference);
}

static t_complexnum	setfactor_numcplx(t_mandel_data *dt, t_imgdata *img)
{
	t_complexnum	cn;

	cn.re = setfactor(dt->maxre, dt->minre, img->width - 1);
	cn.im = setfactor(dt->maxim, dt->minim, img->height - 1);
	return (cn);
}

static void	setmandelzoom(t_mandel_data *data, t_imgdata *img)
{
	t_complexnum	m_pos;

	m_pos.re = data->factor_ncmplx.re * img->x_mouse + data->minre;
	m_pos.im = data->factor_ncmplx.im * img->y_mouse + data->minim;
	data->minre = m_pos.re + (data->minre - m_pos.re) * img->zoom;
	data->maxre = m_pos.re + (data->maxre - m_pos.re) * img->zoom;
	data->minim = m_pos.im + (data->minim - m_pos.im) * img->zoom;
	data->maxim = m_pos.im + (data->maxim - m_pos.im) * img->zoom;
	data->factor_ncmplx = setfactor_numcplx(data, img);
	img->x_mouse = 0;
	img->y_mouse = 0;
}

t_mandel_data	getmandelinitdata(t_imgdata *img)
{
	t_mandel_data	dt;

	dt.hasbeeninit = 1;
	dt.minre = -2.0;
	dt.maxre = 1.0;
	dt.minim = -1.5;
	dt.maxim = dt.minim + img->height * setfactor(dt.maxre, dt.minre, img->width);
	dt.factor_ncmplx = setfactor_numcplx(&dt, img);
	return (dt);
}

void	setmandelnewdata(t_mandel_data *data, t_imgdata *img)
{
	if (img->x_mouse != 0 || img->y_mouse != 0)
		setmandelzoom(data, img);
	else
	{
		data->minre += data->factor_ncmplx.re * img->x_move;
		data->maxre += data->factor_ncmplx.re * img->x_move;
		data->minim += data->factor_ncmplx.im * img->y_move;
		data->maxim += data->factor_ncmplx.im * img->y_move;
		data->factor_ncmplx = setfactor_numcplx(data, img);
		img->x_move = 0.0;
		img->y_move = 0.0;
	}
}
