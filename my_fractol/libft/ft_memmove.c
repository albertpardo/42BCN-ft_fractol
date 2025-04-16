/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:27:38 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/12 13:10:09 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Copies 'n' bytes from memory area "src" to memory area "dst".
 *    The two strings may overlap; the copy is always done in a non-destructive
 *
 *	Returns
 *	  Original "dst"
 *
 */

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*p_dst;
	const char	*p_src;

	p_dst = (char *) dst;
	p_src = (const char *) src;
	if (p_dst != p_src)
	{
		if (p_src > p_dst)
		{
			while (n--)
				*(p_dst++) = *(p_src++);
		}
		else
		{
			p_dst = p_dst + n - 1;
			p_src = p_src + n - 1;
			while (n--)
				*(p_dst--) = *(p_src--);
		}
	}
	return (dst);
}
