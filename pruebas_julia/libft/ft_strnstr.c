/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:29:40 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/12 16:05:49 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Locates the first occurrence of the null-terminated string "needle"
 *  in the string "haystack", where not more than "len" chars are searched.
 *
 * Returns:
 * 	"haystack" , when "needle" == '\0'
 */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = 0;
	if (*needle != '\0')
	{
		i = 0;
		while (haystack[i] && i < len && ptr == 0)
		{
			j = 0;
			while (needle[j] && haystack[i] && i < len && \
					needle[j] == haystack[i])
			{
				i++;
				j++;
			}
			if (needle[j] == '\0')
				ptr = ((char *)&haystack[i - j]);
			i = i - j + 1;
		}
	}
	else
		ptr = (char *)haystack;
	return (ptr);
}
