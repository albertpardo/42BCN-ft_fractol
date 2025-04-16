/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:17:57 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/13 09:58:27 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

/*
 * Create a new substring of length "len" from string "s"
 *
 *  Returns:
 * 	- The new substring of length "len"
 *  - NULL if there is memory problems
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;
	unsigned int	size;

	sub = NULL;
	if (s != NULL && ft_strlen(s) >= start)
	{
		size = ft_strlen(&s[start]);
		if (size < len)
			len = size;
		sub = (char *) malloc(sizeof(char) * (len + 1));
		if (sub != NULL )
		{
			i = 0;
			while (i < len && s[i + start] != '\0')
			{
				sub[i] = s[i + start];
				i++;
			}
			sub[len] = '\0';
		}
	}
	else if (s != NULL)
		sub = ft_strdup("");
	return (sub);
}
