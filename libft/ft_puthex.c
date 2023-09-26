/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:23:04 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/20 18:02:45 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	puthexdigit(unsigned int n, int inupper)
{
	if (n < 10)
		return (ft_putchar((n + '0')));
	else if (inupper)
		return (ft_putchar((n - 10 + 'A')));
	else
		return (ft_putchar((n - 10 + 'a')));
}

int	ft_puthex(unsigned long n, int inupper)
{
	int				count;
	unsigned long	base;

	base = 16;
	count = 0;
	if (n < base)
		count = puthexdigit(n, inupper);
	else
	{
		count = ft_puthex(n / base, inupper);
		if (count > -1)
		{
			if (puthexdigit(n % base, inupper) > -1)
				count++;
		}
	}
	return (count);
}
