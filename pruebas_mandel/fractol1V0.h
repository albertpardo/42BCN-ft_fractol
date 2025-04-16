/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol1V0.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:30:20 by apardo-m          #+#    #+#             */
/*   Updated: 2023/08/28 20:07:48 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL1V0_H
# define FRACTOL1V0_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_X 500
# define MAX_Y 500
# define MAX_ITER 60
# define ESC_KEY 53
# define X_RED 17

typedef struct mlxdata
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}				t_mlxdata;

typedef struct imgdata
{
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fondo_color;
}				t_imgdata;

// 1_colorsV0.c
int			setcolor(int n, const int maxiter);

// 1_mandel_V0.c
void		basic_mandel(int MaxIteration, t_imgdata *img);

//1_mlx_V0.c
void		my_mlx_pixel_put(t_imgdata *data, int x, int y, int color);
int			deal_key(int key, void *win);
int			exit_x(t_mlxdata *win);
t_mlxdata	start_newindow(int w, int h, char *str);
t_imgdata	start_newimage(t_mlxdata win, int color);
#endif
