/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia5V0.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:44:51 by apardo-m          #+#    #+#             */
/*   Updated: 2023/09/09 19:27:04 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Based on mandel4V0.h */

#ifndef JULIA_5V0_H
# define JULIA_5V0_H

/*
# define JULIA_RE -1.3
# define JULIA_IM -0.00525
 */

/*
# define JULIA_RE -0.72
# define JULIA_IM -0.196
 */

/*
# define JULIA_RE -0.1
# define JULIA_IM 0.87
 */

/*
# define JULIA_RE -0.51
# define JULIA_IM -0.601
 */
 
/*
# define JULIA_RE -0.1
# define JULIA_IM 0.87
 */

/*
# define JULIA_RE -0.4
# define JULIA_IM 0.6
 */

# define JULIA_RE -1.9
# define JULIA_IM 0.7

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

t_mandel_data	getmandelinitdata(t_imgdata *img);
void			setmandelnewdata(t_mandel_data *data, t_imgdata *img);

#endif
