/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:56:54 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/12 11:50:40 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Compares byte string "s1" against byte string "s2".
 *   Both strings are assumed to be 'n' bytes long.
 *
 * Return :
 * 		">0" when "s1" > "s2"
 * 		"0"  when "s1" == "s2"
 * 		"<0" when "s1" < "s2"
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				res;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	res = 0;
	while (n && !res)
	{
		if (*ps1 != *ps2)
		{
			res = *ps1 - *ps2;
		}
		ps1++;
		ps2++;
		n--;
	}
	return (res);
}
