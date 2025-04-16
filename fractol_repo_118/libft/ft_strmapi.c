/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:44:43 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/13 14:27:41 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
 * Generaate a new string appliying the function 'f' on each char from 's'
 *
 * Returns
 * 	- A New string.
 * 	- NULL if there is memory problems
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ns;
	size_t	i;

	ns = NULL;
	if (s && f)
	{
		ns = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (ns)
		{
			i = 0;
			while (s[i])
			{
				ns[i] = f(i, s[i]);
				i++;
			}
			ns[i] = '\0';
		}
	}
	return (ns);
}
