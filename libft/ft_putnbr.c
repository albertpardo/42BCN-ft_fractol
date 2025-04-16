/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:35:15 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/20 14:44:32 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

/*
 * Put integer number 'n' in stdio in char format
 *
 * Return :
 * 		- the count of the digits in number
 * 		- -1 for any error
 */

int	ft_putnbr(int n)
{
	char	*strnum;
	int		nlen;

	nlen = -1;
	strnum = ft_itoa(n);
	if (strnum)
	{
		nlen = ft_putstr(strnum);
		free(strnum);
	}
	return (nlen);
}
