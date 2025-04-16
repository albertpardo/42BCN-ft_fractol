/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_zoom-values3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 07:53:18 by apardo-m          #+#    #+#             */
/*   Updated: 2023/09/04 12:53:56 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * En la pantalla del ordenador el 0,0 corresponde a la esquina superior izquieda
 * el eje positivo de X va de izquierda a derecha
 * 	- El valor minimo queda a la izquieda y el maximo a la derecha
 * El eje positivo de Y va de arriba hacia abajo
 * 	- El valor maximo queda arriba y el minimo abajo
 *
 * El zoom se realiza sobre la posicion (X,Y) actual del mouse.
 * El zoom consiste en obtner los nuevos extremos de los limites en el respectivo
 * eje manteniendo el valor complejo que corresponde a la posicion del mouse
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
}				t_mandel_data;

typedef struct	s_img
{
	int		width;
	int 	height;
	int		x_mouse;
	int 	y_mouse;
	double	zoom;
}				t_imgdata;

static double	getfactor( double max, double min, int reference)
{
	return ((max - min) / reference);
}

static double	maxValue(double xtrm, t_mandel_data *dt, t_imgdata *img)
{
	return(xtrm + img->height * getfactor(dt->maxre, dt->minre, img->width));
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

int main(void)
{
	t_mandel_data	data;
	t_imgdata		img;
	t_complexnum	c_mpos;
	t_complexnum	abs_c_mpos;
	double			oldmin;
	double			oldmax;
	int				xm;

	img.x_mouse = 8;   // 499 - 125;
	img.y_mouse = 8;  // 249;
	img.width =  8; //500;
	img.height = 8; //500;
	img.zoom = 1.0 / 2.0;

	data.hasbeeninit = 1;
	data.minre = -2.0;
	data.maxre = 6.0; //1.0;
	data.minim = -2.0; //-1.5;
	data.maxim = maxValue(data.minim, &data, &img);

	xm = 0;
	while(xm <= img.width)
	{
		data.minre = -2.0;
		data.maxre = 6.0; //1.0;
		data.minim = -2.0; //-1.5;
		data.maxim = maxValue(data.minim, &data, &img);
		img.x_mouse = xm++;
		c_mpos = getcnmouse(&data, &img);
		printf("------------------------\n");
		printf("Antes   : (%d,%d) . (%f,j%f) [(%f,%f), j(%f,%f)]\n", img.x_mouse, img.y_mouse, c_mpos.re, c_mpos.im, data.minre, data.maxre, data.maxim, data.minim);

		oldmin = data.minre;
		oldmax = data.maxre;
		data.minre = getlowlimit(img.zoom, oldmax, oldmin, img.width, img.x_mouse);
		data.maxre = getuplimit(data.minre, img.zoom, oldmax, oldmin);
		oldmin = data.minim;
		oldmax = data.maxim;
		data.maxim = getlowlimit(img.zoom, oldmin, oldmax, img.height, img.y_mouse);
		data.minim = getuplimit(data.maxim, img.zoom, oldmin, oldmax);

		c_mpos = getcnmouse(&data, &img);

		printf("Despues : (%d,%d) . (%f,j%f) [(%f,%f), j(%f,%f)]\n", img.x_mouse, img.y_mouse, c_mpos.re, c_mpos.im, data.minre, data.maxre, data.maxim, data.minim);
	}
	return (0);
}
