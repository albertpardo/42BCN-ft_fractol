/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:13:26 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/13 11:03:16 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

/*
 *	Make a copy of the string "s1" whithout any of the chars that are in "set"
 *	  and appears at the start or the end of "s1"
 *
 *  Returns:
 *  	- The new string
 *  	- NULL if there is any memory problem.
 */

static unsigned	int	isinset(char const c, char const *set)
{
	int	inset;
	int	i;

	inset = 0;
	i = 0;
	while (set[i] != '\0' && c != set[i])
		i++;
	if (c == set[i])
		inset = 1;
	return (inset);
}

static char	*my_strndup(const char *s1, size_t n)
{
	char	*np;

	np = ft_calloc(1, sizeof(char) * (n + 1));
	if (np)
		ft_memcpy(np, s1, n);
	return (np);
}

static char	*my_strtrim(char const *s1, char const *set)
{
	char	*np;
	char	*pi;
	int		i;

	np = NULL;
	i = 0;
	while (s1[i] != '\0' && isinset(s1[i], set))
		i++;
	if (s1[i] != '\0')
	{
		pi = (char *)&s1[i];
		i = ft_strlen(s1) - 1;
		while (&s1[i] > pi && isinset(s1[i], set))
			i--;
		if (&s1[i] >= pi)
			np = my_strndup(pi, &s1[i] - pi + 1);
	}
	else
		np = ft_calloc(1, sizeof(char));
	return (np);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*np;

	np = NULL;
	if (s1 && set)
		np = my_strtrim(s1, set);
	else if (s1 && !set)
		np = ft_strdup(s1);
	else
		np = ft_calloc(1, sizeof(char));
	return (np);
}
