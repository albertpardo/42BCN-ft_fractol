/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_mandel_V0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:11:07 by apardo-m          #+#    #+#             */
/*   Updated: 2023/08/30 15:39:30 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Put mandelbrot figure with colors on screen
 * The keys UP, DOWN, LEFT , RIGHT , move the mandelbrot figure
 */

#include "fractol2V0.h"

typedef struct complexnum
{
	double	re;
	double	im;
}				t_complexnum;

typedef struct initial_mandel_data
{
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	double	re_factor;
	double	im_factor;

}				t_initmandel;

static int	inoutmandel(t_complexnum c, int MaxIteration)
{
	t_complexnum	z;
	t_complexnum	z2;
	int				n;

	z.re = c.re;
	z.im = c.im;
	z2.re = z.re * z.re;
	z2.im = z.im * z.im;
	n = 0;
	while ((z2.re + z2.im) < 4 && n < MaxIteration)
	{
		z.im = 2 * z.re * z.im + c.im;
		z.re = z2.re - z2.im + c.re;
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		n++;
	}
	return (n);
}

t_initmandel	getmandelinitdata(t_imgdata *img)
{
	t_initmandel	dt;

	dt.minre = -2.0;
	dt.maxre = 1.0;
	dt.minim = -1.5;
	dt.maxim = dt.minim + img->height * (dt.maxre - dt.minre) / img->width;
	dt.re_factor = (dt.maxre - dt.minre) / (img->width - 1);
	dt.im_factor = (dt.maxim - dt.minim) / (img->height - 1);
	dt.minre += dt.re_factor * img->x_move;
	dt.maxre += dt.re_factor * img->x_move;
	dt.minim += dt.im_factor * img->y_move;
	dt.maxim += dt.im_factor * img->y_move;
	return (dt);
}

void	basic_mandel(int maxiteration, t_imgdata *img)
{
	int				x;
	int				y;
	int				n;
	t_complexnum	c;
	t_initmandel	mandeldata;

	mandeldata = getmandelinitdata(img);
	y = 0;
	while (y < img->height)
	{
		c.im = mandeldata.maxim - y * mandeldata.im_factor;
		x = 0;
		while (x < img->width)
		{
			c.re = mandeldata.minre + x * mandeldata.re_factor;
			n = inoutmandel(c, maxiteration);
			my_mlx_pixel_put(img, x, y, setcolor(n, maxiteration));
			x++;
		}
		y++;
	}
}
