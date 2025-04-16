/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel3V0.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:58:12 by apardo-m          #+#    #+#             */
/*   Updated: 2023/08/31 12:24:42 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDEL3V0_H
# define MANDEL3V0_H

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
//	double	re_factor;
//	double	im_factor;

}				t_mandel_data;

t_mandel_data	getmandelinitdata(t_imgdata *img);
void			setmandelnewdata(t_mandel_data *data, t_imgdata *img);

#endif
