/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_mandel_V0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:59:20 by apardo-m          #+#    #+#             */
/*   Updated: 2023/09/04 15:50:58 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Based on 2_mandel_V0.c
 *
 * Put mandelbrot figure with colors on screen
 * The keys UP, DOWN, LEFT , RIGHT , move the mandelbrot figure
 * 
 * Mouse sc
 *
 * In this version a "static struct is used for the mandelbrot data"
 *
 */

#include "fractol3V0.h"
#include "mandel3V0.h"

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

void	basic_mandel(int maxiter, t_imgdata *img)
{
	int						x;
	int						y;
	t_complexnum			c;
	static t_mandel_data	mdat;

	if (!mdat.hasbeeninit)
		mdat = getmandelinitdata(img);
	else
		setmandelnewdata(&mdat, img);
	y = 0;
	while (y < img->height)
	{
		c.im = (mdat.minim - mdat.maxim) / img->height * y + mdat.maxim;
		x = 0;
		while (x < img->width)
		{
			c.re = (mdat.maxre - mdat.minre) / img->width * x + mdat.minre;
			my_put_pixel(img, x, y, setcolor(inoutmandel(c, maxiter), maxiter));
			x++;
		}
		y++;
	}
}
