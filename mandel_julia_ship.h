/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia_ship.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:25:35 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/13 19:30:03 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDEL_JULIA_SHIP_H
# define MANDEL_JULIA_SHIP_H

typedef struct complexnum
{
	double	re;
	double	im;
}				t_complexnum;

typedef struct s_mandel_data
{
	int				hasbeeninit;
	double			minre;
	double			maxre;
	double			minim;
	double			maxim;
	t_complexnum	factor_ncmplx;
}				t_mandel_data;

t_mandel_data	getmandelinitdata(t_imgdata *img);
void			setmandelnewdata(t_mandel_data *data, t_imgdata *img);

#endif
