/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:50:33 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/12 11:38:16 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * locates the first occurrence of c (as unsigned char) in the range n of
 *      the string s 
 *
 * Returns :
 * 		Pointer to the byte locates
 * 		or
 * 		NULL for no occurrence
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;
	unsigned char	*find_c;

	us = (unsigned char *) s;
	find_c = NULL;
	while (n && !find_c)
	{
		if (*us == (unsigned char) c)
			find_c = us;
		else
		{
			us++;
			n--;
		}
	}
	return (find_c);
}
