/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_julia_V0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:40:53 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/10 18:08:29 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Based on 4_mandel_V2.c
 *
 * Put mandelbrot figure with colors on screen
 * The keys UP, DOWN, LEFT , RIGHT , move the mandelbrot figure
 * 
 * Mouse sc
 *
 * In this version a "static struct is used for the mandelbrot data"
 *
 */

#include "fractol5V0.h"
#include "julia5V0.h"

static int	inoutjulia(t_complexnum c, t_complexnum jc, int MaxIteration)
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
		z.im = 2 * z.re * z.im + jc.im;
		z.re = z2.re - z2.im + jc.re;
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		n++;
	}
	return (n);
}

void	basic_julia(int maxiter, t_imgdata *img)
{
	int						x;
	int						y;
	t_complexnum			c;
	t_complexnum			jc;
	static t_mandel_data	mdat;
	int						color;

	if (!mdat.hasbeeninit)
		mdat = getmandelinitdata(img);
	else
		setmandelnewdata(&mdat, img);
	y = 0;
	printf("Active palete = %d\n", img->act_plte);
	jc.im = JULIA_IM;
	jc.re = JULIA_RE;

	while (y < img->height)
	{
		c.im = (mdat.minim - mdat.maxim) / img->height * y + mdat.maxim;
		x = 0;
		while (x < img->width)
		{
			c.re = (mdat.maxre - mdat.minre) / img->width * x + mdat.minre;
			color = setcolor(img->act_plte, inoutjulia(c, jc, maxiter), maxiter);
			my_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}
