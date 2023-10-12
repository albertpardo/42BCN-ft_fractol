/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:18:56 by apardo-m          #+#    #+#             */
/*   Updated: 2023/10/11 14:41:27 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

#include "./libft/libft.h"
#include "./libft/ft_printf.h"
#include "cli.h"
#include "fractol.h"

#define KO_MESSAGE "||   No  valid arguments.  ||"
#define KO_JULIA_MESSAGE "||   No  valid arguments for Julia.  ||" 
#define JULIA_RE -1.9
#define JULIA_IM 0.7

static void	printinfo(void)
{
	ft_printf("Choose the number from the next fractals:\n");
	ft_printf("\t- 1) Mandelbrot fractal.\n");
	ft_printf("\t- 2) Julia fractal\n");
	ft_printf("\t- 3) TODEFINE fractal\n");
	ft_printf("\nUsage:\n");
	ft_printf("./fractol [Fractal_Number]\n\n");
	ft_printf("Julia has two optional params. Julia usage:\n");
	ft_printf("./fractol 2 [real] [imaginary]\n\n");
	ft_printf("Info for Julia params :\n");
	ft_printf("- They must comply: (real^2 + imaginary^2) =< 4.\n");
	ft_printf("- When they are not indicated, default values are used.\n");
	ft_printf("Examples of use:\n");
	ft_printf("\t- Maldebrot: ./fractol 1\n");
	ft_printf("\t- Julia    : ./fractol 2\n");
	ft_printf("\t- Julia    : ./fractol 2 -0.4 0.5\n");
}

static void	printnovalid(char *str)
{
	ft_printf("%s\n\n", str);
	printinfo();
}

static void	managerargsjulia(char *cre, char *cim)
{
	double	re;
	double	im;

	ft_printf("\nJulia selected with arguments.\n");
	ft_printf("\tArguments to be tested : '%s' and '%s'\n\n", cre, cim);
	if (istrtodoublevalidformat(cre) && istrtodoublevalidformat(cim))
	{
		re = ft_mystrtod(cre);
		im = ft_mystrtod(cim);
		ft_printf("\t Conversion: \n");
		printf("\t\treal = %f, img = %f\n", re, im);
		if ((re * re + im * im) <= 4.0)
		{
			mandel_julia(JULIA_SET, re, im);
			ft_printf("\nJulia selected with valid arguments\n");
			mandel_julia(MANDEL_SET, re, im);
		}
		else
			ft_printf("\nArguments must be : (real^2 + imaginary^2) =< 4.\n");
	}
	else
		printnovalid(KO_JULIA_MESSAGE);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_strlen(argv[1]) == 1 && argv[1][0] == '1')
	{
		ft_printf("Maldenbrot selected\n");
		mandel_julia(MANDEL_SET, 0.0, 0.0);
	}
	else if (argc == 2 && ft_strlen(argv[1]) == 1 && argv[1][0] == '2')
	{
		ft_printf("Julia selected without arguments\n");
		mandel_julia(JULIA_SET, JULIA_RE, JULIA_IM);
	}
	else if (argc == 2 && ft_strlen(argv[1]) == 1 && argv[1][0] == '3')
		ft_printf("TODEFINE fractal selected\n");
	else if (argc == 4 && ft_strlen(argv[1]) == 1 && argv[1][0] == '2' )
		managerargsjulia(argv[2], argv[3]);
	else
		printnovalid(KO_MESSAGE);
	return (0);
}
