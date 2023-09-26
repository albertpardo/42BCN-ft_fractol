/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:22:32 by apardo-m          #+#    #+#             */
/*   Updated: 2023/09/13 12:10:54 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

static int	putformat(va_list ap, char const *fmt)
{
	int	len;

	len = 0;
	if (*fmt == '%')
		len = ft_putchar(*fmt);
	else if (*fmt == 'c')
		len = charprintf(ap);
	else if (*fmt == 's')
		len = strprintf(ap);
	else if (*fmt == 'i' || *fmt == 'd')
		len = nbrprintf(ap);
	else if (*fmt == 'u')
		len = unsignbrprintf(ap);
	else if (*fmt == 'x' || *fmt == 'X')
		len = hexprintf(ap, *fmt);
	else if (*fmt == 'p')
		len = pointerprintf(ap);
	else
		len = -1;
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list					ap;
	int						count;
	int						len;

	count = 0;
	va_start(ap, format);
	while (*format && count > -1)
	{
		len = 0;
		if (*format == '%')
		{
			if (*(++format))
				len = putformat(ap, format);
		}
		else
			len = ft_putchar(*format);
		if (len > -1)
			count += len;
		else
			count = -1;
		format++;
	}
	va_end(ap);
	return (count);
}
