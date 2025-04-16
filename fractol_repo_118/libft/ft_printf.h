/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:48:40 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/20 14:39:02 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

int	ft_printf(char const *fmt, ...);
int	charprintf(va_list ap);
int	strprintf(va_list ap);
int	pointerprintf(va_list ap);
int	hexprintf(va_list ap, char isX);
int	nbrprintf(va_list ap);
int	unsignbrprintf(va_list ap);

#endif
