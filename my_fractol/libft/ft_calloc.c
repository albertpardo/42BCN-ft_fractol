/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:16:50 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/12 10:42:14 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

/*
 *	Reserve space memory for "counts" object of "size" bytes.
 *	The space memory is filled with bytes of falue zero.
*/

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	psize;

	p = NULL;
	psize = sizeof(char) * count * size;
	p = malloc(psize);
	if (p && psize)
		ft_bzero(p, psize);
	return (p);
}
