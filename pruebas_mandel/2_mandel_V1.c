/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_mandel_V1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:55:40 by apardo-m          #+#    #+#             */
/*   Updated: 2023/08/30 16:03:35 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Put mandelbrot figure with colors on screen
 * The keys UP, DOWN, LEFT , RIGHT , move the mandelbrot figure
 *
 * In this version a "static struct is used for the mandelbrot data"
 *
 */

#include "fractol2V0.h"

typedef struct complexnum
{
	double	re;
	double	im;
}				t_complexnum;

typedef struct s_mandel_data
{
	int		hasbeeninit;
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	double	re_factor;
	double	im_factor;

}				t_mandel_data;

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

static t_mandel_data	setmandelinitdata(t_imgdata *img)
{
	t_mandel_data	dt;

	dt.hasbeeninit = 1;
	dt.minre = -2.0;
	dt.maxre = 1.0;
	dt.minim = -1.5;
	dt.maxim = dt.minim + img->height * (dt.maxre - dt.minre) / img->width;
	dt.re_factor = (dt.maxre - dt.minre) / (img->width - 1);
	dt.im_factor = (dt.maxim - dt.minim) / (img->height - 1);
	return (dt);
}

static t_mandel_data	getmandelnewdata(t_mandel_data data, t_imgdata *img)
{
	data.minre += data.re_factor * img->x_move;
	data.maxre += data.re_factor * img->x_move;
	data.minim += data.im_factor * img->y_move;
	data.maxim += data.im_factor * img->y_move;
	data.re_factor = (data.maxre - data.minre) / (img->width - 1);
	data.im_factor = (data.maxim - data.minim) / (img->height - 1);
	img->x_move = 0.0;
	img->y_move = 0.0;
	return (data);
}

void	basic_mandel(int maxiteration, t_imgdata *img)
{
	int						x;
	int						y;
	int						n;
	t_complexnum			c;
	static t_mandel_data	mandeldata;

	if (!mandeldata.hasbeeninit)
		mandeldata = setmandelinitdata(img);
	else
		mandeldata = getmandelnewdata(mandeldata, img);
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
