/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:51:27 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/13 14:21:29 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

/*
 * Converts a integer number 'n' to it's representation as string
 *
 * Returns
 * 	A new string with the int number convertion to String
 */

static unsigned int	countdigits(int num)
{
	int	n;

	n = 1;
	while (num > 9)
	{
		num = num / 10;
		n++;
	}
	return (n);
}

static void	convert_int_to_char(char *chnum, int num, int nf)
{
	int	quotient;

	quotient = num;
	while (nf)
	{
		chnum[nf -1] = (quotient % 10) + '0';
		quotient /= 10;
		nf--;
	}
}

static char	*myitoa(int isnegative, int num)
{
	char			*chint;
	unsigned int	nf;

	nf = countdigits(num);
	chint = (char *) ft_calloc(1, sizeof(char) * (nf + isnegative + 1));
	if (chint)
	{
		if (isnegative)
		{
			chint[0] = '-';
			convert_int_to_char(&chint[1], num, nf);
		}
		else
			convert_int_to_char(chint, num, nf);
	}
	return (chint);
}

char	*ft_itoa(int num)
{
	int				isnegative;
	char			*chint;

	isnegative = 0;
	if ((num < 0) && (num != -2147483648))
	{
		num *= -1;
		isnegative = 1;
	}
	if (num >= 0)
		chint = myitoa(isnegative, num);
	else
		chint = ft_strdup("-2147483648");
	return (chint);
}
