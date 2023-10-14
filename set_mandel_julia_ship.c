/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mandel_julia_ship.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:27:40 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/14 19:55:53 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mandel_julia_ship.h"

static double	my_abs(double n)
{
	if (n < 0.0)
		return (-n);
	else
		return (n);
}

static void	set_ct_julia(t_complexnum *ct, t_imgdata *img)
{
	ct->re = img->julia_re;
	ct->im = img->julia_img;
}

static int	getval(t_complexnum c, int MaxIteration, t_imgdata *img )
{
	t_complexnum	z;
	t_complexnum	z2;
	t_complexnum	ct;
	int				n;

	z.re = c.re;
	z.im = c.im;
	z2.re = z.re * z.re;
	z2.im = z.im * z.im;
	ct.re = c.re;
	ct.im = c.im;
	n = 0;
	if (img->fractol_set == JULIA_SET)
		set_ct_julia(&ct, img);
	while ((z2.re + z2.im) < 4 && n++ < MaxIteration)
	{
		if (img->fractol_set != SHIP_SET)
			z.im = 2 * z.re * z.im + ct.im;
		else
			z.im = my_abs(2 * z.re * z.im) + ct.im;
		z.re = z2.re - z2.im + ct.re;
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
	}
	return (n);
}

void	set_mandel_julia_ship(int maxiter, t_imgdata *img)
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
			my_put_pixel(img, x, y, \
				setcolor(img->act_plte, getval(c, maxiter, img), maxiter));
			x++;
		}
		y++;
	}
}
