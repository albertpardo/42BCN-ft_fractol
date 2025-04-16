/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:00:21 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/20 13:55:15 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsignbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
		count = ft_putchar(n + '0');
	else
	{
		count = ft_putunsignbr(n / 10);
		if (count > -1)
		{
			if (ft_putchar(n % 10 + '0') > -1)
				count ++;
		}
	}
	return (count);
}
