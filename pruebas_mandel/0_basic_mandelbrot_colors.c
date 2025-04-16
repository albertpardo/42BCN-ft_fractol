/*
 * https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#pushing-images-to-a-window
 *
 * Mandelbrot : http://warp.povusers.org/Mandelbrot/
 * 
 */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_X 500
#define MAX_Y 500
#define MAX_ITER 60
#define ESC_KEY 53	

typedef struct mlxdata
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}				t_mlxdata;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fondo_color;
}				t_data;

typedef struct	complexnum
{
	double	re;
	double	im;
}				t_complexnum;
			
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst; // Acces to pixel postion in *data

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;  //Change the pixel color
}

// Color functions
int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

// 				n to a color so that from 0 to MaxIterations/2-1 the color goes from black (0x0) to red(0x00FF0000) and from MaxIterations/2 to MaxIterations-1 the color goes from red(0x00FF0000) to white(0x00FFFFFF)
int setcolor(int n, const int maxiter)
{
	int component;

	component = n * 0xFF * 2 / maxiter;
	if ( n < (maxiter / 2))
		return (create_trgb(0x00, component, 0x0, 0x0));
	else if (n < maxiter)
		return (create_trgb(0x00, 0xFF, component, component));
	else
		return (0xFF000000);
}

// End color function


int	exit_x(t_mlxdata *win)
{
	mlx_destroy_window (win->mlx_ptr, win->win_ptr);
	exit (1);  // Close Windows and finish the program`
}

int deal_key(int key, void *win)
{
	if (key == 53) // ESC Key = 53
		exit_x(win);
	return (0);
} 

t_mlxdata start_newindow(int w, int h, char *str)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, w, h, str);
	return ((t_mlxdata) {mlx_ptr, win_ptr, w, h});
}

t_data start_newimage(t_mlxdata	win, int color)
{
	t_data	img;

	img.img = mlx_new_image(win.mlx_ptr, win.width, win.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.height = win.height;
	img.width = win.width;
	img.fondo_color = color;
	return((t_data) {img.img, img.addr, img.height, img.width, img.bits_per_pixel, \
			img.line_length, img.endian, img.fondo_color});
}

/*
int inoutmadel( t_complexnum c, int MaxIteration)
{
	t_complexnum	Z;
	t_complexnum	Z2;
	int				n;

	Z.re = c.re;
	Z.im = c.im;
	n = 0;
   	while(n < MaxIteration)
	{
		Z2.re = Z.re * Z.re;
		Z2.im = Z.im * Z.im;
		if(Z2.re + Z2.im > 4)
			return (n);
		Z.im = 2 * Z.re * Z.im + c.im;
		Z.re = Z2.re - Z2.im + c.re;
		n++;
	}
	return (n);
}
*/

int inoutmadel( t_complexnum c, int MaxIteration)
{
	t_complexnum	Z;
	t_complexnum	Z2;
	int				n;

	Z.re = c.re;
	Z.im = c.im;
	Z2.re = Z.re * Z.re;
	Z2.im = Z.im * Z.im;
	n = 0;
   	while((Z2.re + Z2.im) < 4 && n < MaxIteration)
	{
		Z.im = 2 * Z.re * Z.im + c.im;
		Z.re = Z2.re - Z2.im + c.re;
		Z2.re = Z.re * Z.re;
		Z2.im = Z.im * Z.im;
		n++;
	}
	return (n);
}

void basic_mandel(int MaxIteration, t_data *img)
{
	double			MinRe;
	double			MaxRe;
	double			MinIm;
	double			MaxIm;
	double			Re_factor;
	double			Im_factor;
	int				x;
	int				y;
	int				n;
	t_complexnum	c;

	MinRe = -2.0;
	MaxRe = 1.0;
	MinIm = -1.5;
	MaxIm = 1.5;
	Re_factor = (MaxRe - MinRe) / (img->width - 1);
	Im_factor = (MaxIm - MinIm) / (img->height - 1);
	y = 0;
	while(y < img->height)
	{
		c.im = MaxIm - y * Im_factor;
		x = 0;
		while(x < img->width)
		{
			c.re = MinRe + x * Re_factor;
			n =  inoutmadel( c, MaxIteration);
			my_mlx_pixel_put(img, x, y, setcolor(n, MaxIteration));
			x++;
    	}
		y++;
	}
}

/*
void basic_mandel(int MaxIteration, t_data *img)
{
	double			MinRe;
	double			MaxRe;
	double			MinIm;
	double			MaxIm;
	double			Re_factor;
	double			Im_factor;
	int				x;
	int				y;
	int				n;
	int				isInside;
	t_complexnum	c;
	t_complexnum	Z;
	t_complexnum	Z2;

	MinRe = -2.0;
	MaxRe = 1.0;
	MinIm = -1.5;
	MaxIm = 1.5;
	Re_factor = (MaxRe - MinRe) / (img->width - 1);
	Im_factor = (MaxIm - MinIm) / (img->height - 1);
	y = 0;
	while(y < img->height)
	{
		c.im = MaxIm - y * Im_factor;
		x = 0;
		while(x < img->width)
		{
			c.re = MinRe + x * Re_factor;
			Z.re = c.re;
			Z.im = c.im;
			isInside = 1;
			n = 0;
       	 	while(n < MaxIteration)
			{
				Z2.re = Z.re * Z.re;
				Z2.im = Z.im * Z.im;
				if(Z2.re + Z2.im > 4)
				{
					isInside = 0;
					break;
				}
				Z.im = 2 * Z.re * Z.im + c.im;
				Z.re = Z2.re - Z2.im + c.re;
				n++;
			}
			if(isInside) 
				my_mlx_pixel_put(img, x, y, 0xFF000000);
			else
// 				Determinar color (x,y, n)
// 				n to a color so that from 0 to MaxIterations/2-1 the color goes from black (0x0) to red(0x00FF0000) and from MaxIterations/2 to MaxIterations-1 the color goes from red(0x00FF0000) to white(0x00FFFFFF)
				my_mlx_pixel_put(img, x, y, setcolor(n, MaxIteration));
			x++;
    	}
		y++;
	}
}
*/

int	main(void)
{
	t_data		img;
	t_mlxdata	win;

	win = start_newindow(MAX_X, MAX_Y, "Basic Mandelbrot");
	if (win.mlx_ptr != NULL && win.win_ptr != NULL)
	{
		img = start_newimage(win, 0x007F7F7F);
//		basic_mandel(MAX_ITER, &img, 0xFF000000);
		basic_mandel(MAX_ITER, &img);
		mlx_key_hook(win.win_ptr, deal_key, &img);
		mlx_hook(win.win_ptr, 17, 1L<<0, &exit_x, &win);
		mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, img.img, 0, 0);
		mlx_loop(win.mlx_ptr);
	}
	else
		return (1);
	return (0);
}
