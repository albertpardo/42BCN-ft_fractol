/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:50:59 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/11 14:51:40 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDEL_JULIA_H
# define MANDEL_JULIA_H

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
