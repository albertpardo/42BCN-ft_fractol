# include <stdio.h>
# include <stdlib.h>

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
	t_complexnum factor_ncmplx;

}				t_mandel_data;

typedef struct	s_img
{
	int		width;
	int 	height;
	int		x_mouse;
	int 	y_mouse;
	double	zoom;
}				t_imgdata;

static double	setfactor( double max, double min, int reference)
{
	return ((max - min) / reference);
}

static double	maxValue(double xtrm, t_mandel_data *dt, t_imgdata *img)
{
	return(xtrm + img->height * setfactor(dt->maxre, dt->minre, img->width));
}

static t_complexnum	setfactor_numcplx(t_mandel_data *dt, t_imgdata *img)
{
	t_complexnum	cn;

	cn.re = setfactor(dt->maxre, dt->minre, img->width - 1);
	cn.im = setfactor(dt->maxim, dt->minim, img->height - 1);
	return (cn);
}

int main(void)
{
	t_mandel_data	data;
	t_complexnum	m_pos;
	t_imgdata		img;

	img.x_mouse = 249;
	img.y_mouse = 10;
	img.width = 500;
	img.height = 450;
	img.zoom = 1.003;

	data.hasbeeninit = 1;
	data.minre = -2.0;
	data.maxre = 1.0;
	data.minim = -1.5;
	data.maxim = maxValue(data.minim, &data, &img);
	data.factor_ncmplx = setfactor_numcplx(&data, &img);

	m_pos.re = data.factor_ncmplx.re * img.x_mouse + data.minre;
	m_pos.im = data.factor_ncmplx.im * img.y_mouse + data.minim;

	printf("Antes:(%d,%d) . (%f,j%f) [(%f,%f), j(%f,%f)]\n", img.x_mouse, img.y_mouse, m_pos.re, m_pos.im, data.minre, data.maxre, data.minim, data.maxim);
	printf("factor = %f, %f\n", data.factor_ncmplx.re, data.factor_ncmplx.im);
	
	if (img.x_mouse < img.width / 2)
	{	
		data.minre *= 1/img.zoom;
		data.maxre = (m_pos.re - data.minre) * img.width / img.x_mouse + data.minre;
	}
	else
	{
		data.maxre *= 1/img.zoom;
		data.minre = img.width * (data.maxre - m_pos.re) / (img.width - img.x_mouse) - data.maxre;
	}

	data.factor_ncmplx = setfactor_numcplx(&data, &img);
	m_pos.re = data.factor_ncmplx.re * img.x_mouse + data.minre;
	m_pos.im = data.factor_ncmplx.im * img.y_mouse + data.minim;

	printf("Despues:(%d,%d) . (%f,j%f) [(%f,%f), j(%f,%f)]\n", img.x_mouse, img.y_mouse, m_pos.re, m_pos.im, data.minre, data.maxre, data.minim, data.maxim);

	printf("factor = %f, %f\n", data.factor_ncmplx.re, data.factor_ncmplx.im);
	

	return (0);
}
