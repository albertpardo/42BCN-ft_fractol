/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:23:32 by apardo-m          #+#    #+#             */
/*   Updated: 2023/08/04 16:00:03 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Returns
 * 	The position of the first occurrence of "(char) c" in "*s".
 * 		 If c == '\0' is part of the string
 * 	NULL for no ocurrence
 */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	un_c;

	un_c = (unsigned char) c;
	while (*s != '\0' && *s != un_c)
		s++;
	if (*s == '\0' && *s != un_c)
		s = NULL;
	return ((char *) s);
}
