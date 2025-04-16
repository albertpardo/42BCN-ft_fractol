/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:24:04 by apardo-m          #+#    #+#             */
/*   Updated: 2023/07/19 16:55:47 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
 *  Allocates sufficient memory for a copy of the string "s1", does the copy, 
 *  and returns a pointer to it
 */

/*
char	*ft_strdup(const char	*s1)
{
	char	*prt_str;
	size_t	ptr_str_size;

	ptr_str_size = (ft_strlen(s1) + 1) * sizeof(char);
	prt_str = (char *) malloc(ptr_str_size);
	if (prt_str)
		ft_strlcpy(prt_str, s1, ptr_str_size);
	return (prt_str);
}
*/

char	*ft_strdup(const char	*s1)
{
	char	*ptr_str;
	int		i;

	ptr_str = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (ptr_str)
	{
		i = 0;
		while (s1[i])
		{
			ptr_str[i] = s1[i];
			i++;
		}
		ptr_str[i] = '\0';
	}
	return (ptr_str);
}
