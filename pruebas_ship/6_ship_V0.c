/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ship_V0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:42:41 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/14 15:45:09 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Based on  5_julia_V0.c
 *
 */

#include "fractol5V0.h"
#include "julia5V0.h"

static double my_abs(double n)
{
	if (n < 0.0)
		return (-n);
	else
		return (n);
}

static int	inout(t_complexnum c, int MaxIteration)
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
		z.im = my_abs(2 * z.re * z.im) + c.im;
		z.re = z2.re - z2.im + c.re;
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		n++;
	}
	return (n);
}

void	basic_ship(int maxiter, t_imgdata *img)
{
	int						x;
	int						y;
	t_complexnum			c;
	static t_mandel_data	mdat;
	int						color;

	if (!mdat.hasbeeninit)
		mdat = getmandelinitdata(img);
	else
		setmandelnewdata(&mdat, img);
	y = 0;
	printf("Active palete = %d\n", img->act_plte);

	while (y < img->height)
	{
		c.im = (mdat.minim - mdat.maxim) / img->height * y + mdat.maxim;
		x = 0;
		while (x < img->width)
		{
			c.re = (mdat.maxre - mdat.minre) / img->width * x + mdat.minre;
			color = setcolor(img->act_plte, inout(c, maxiter), maxiter);
			my_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}
