/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:31:44 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/12 15:24:06 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Lexicographically compare not more than 'n' characters from  null-terminated 
 *   strings "s1" and "s2"
 * Characters that appear after a `\0' character are not compared.
 *
 * Returns:
 * 		">0" when "s1" > "s2"
 * 		"0"  when "s1" == "s2"
 * 		"<0" when "s1" < "s2" 
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	while (n && *ps1 && *ps2 && *ps1 == *ps2)
	{
		ps1++;
		ps2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*ps1 - *ps2);
}
