/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:09:38 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/12 12:12:20 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Copies 'n' bytes from memory area "src" to memory area "dst".
 *	  If "dst" and "src" overlap, behavior is undefined
 *
 *	Returns
 *	  Original "dst"
 *	  
 */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p_dst;
	const char	*p_src;

	p_dst = (char *) dst;
	p_src = (const char *) src;
	if (p_src != p_dst)
	{
		while (n)
		{
			*p_dst = *p_src;
			p_dst++;
			p_src++;
			n--;
		}
	}
	return (dst);
}
