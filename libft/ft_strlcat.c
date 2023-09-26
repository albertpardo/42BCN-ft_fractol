/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:54:25 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/13 11:02:53 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
 *	Appends string "src" to the end of "dst".  It will append at most
 *     "(dstsize - 1) - strlen(dst)" chars to be NUL-terminate,
 *  Not NULL termiante for:
 *    -  dstsize ==  0
 *    -  the original "dst" string  >  "dstsize" (in practice this should not 
 *    		happen as it means that either "dstsize" is incorrect or that "dst"
 *    		is not a proper string).
 *  If the src and dst strings overlap, the behavior is undefined.
 *
 *  RETURNS:
 *  	The initial length of "dst" plus the length of "src"
 *		If the return value is ">= dstsize", the output string has been
 *		 truncated. It is the caller's responsibility to handle this
 */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_original_size;
	size_t	dst_final_size;
	size_t	src_size;
	size_t	i;
	size_t	j;

	dst_original_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize > 0 && ((dstsize - 1) >= dst_original_size))
	{
		i = 0;
		j = dst_original_size;
		while (src[i] && j < (dstsize - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	if (dstsize >= dst_original_size)
		dst_final_size = dst_original_size + src_size;
	else
		dst_final_size = dstsize + src_size;
	return (dst_final_size);
}
