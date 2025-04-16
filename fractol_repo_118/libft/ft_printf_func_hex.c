/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:44:43 by apardo-m          #+#    #+#             */
/*   Updated: 2023/09/13 12:12:09 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	pointerprintf(va_list ap)
{
	int	len;

	len = ft_putstr("0x");
	if (len == 2)
	{
		len = ft_puthex(va_arg(ap, unsigned long int), 0);
		if (len > -1)
			len += 2;
	}
	return (len);
}

int	hexprintf(va_list ap, char isX)
{
	unsigned int	uln;

	uln = va_arg(ap, unsigned int);
	if (isX == 'X')
		return (ft_puthex(uln, 1));
	else
		return (ft_puthex(uln, 0));
}
