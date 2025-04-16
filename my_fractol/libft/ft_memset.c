/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:22:54 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/12 11:03:48 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
 *  writes len bytes of value c (as unsigned char) to the string b
 */

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ub;

	ub = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		ub[i] = (unsigned int) c;
		i++;
	}
	return (b);
}
