/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func_nbrs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:49:30 by apardo-m          #+#    #+#             */
/*   Updated: 2023/09/13 12:12:50 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	nbrprintf(va_list ap)
{
	return (ft_putnbr(va_arg(ap, int)));
}

int	unsignbrprintf(va_list ap)
{
	unsigned int	un;

	un = va_arg(ap, unsigned int);
	if (un < 0)
		un = -un;
	return (ft_putunsignbr(un));
}
