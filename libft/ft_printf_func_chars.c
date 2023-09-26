/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func_chars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:47:26 by apardo-m          #+#    #+#             */
/*   Updated: 2023/09/13 12:11:44 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	charprintf(va_list ap)
{
	return (ft_putchar(va_arg(ap, int)));
}

int	strprintf(va_list ap)
{
	return (ft_putstr(va_arg(ap, char *)));
}
