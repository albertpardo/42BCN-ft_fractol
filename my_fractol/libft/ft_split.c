/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:10:58 by apardo-m          #+#    #+#             */
/*   Updated: 2023/07/02 21:28:28 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
 * Make a divison of the string 's' into substrings using the char 'c' as
 * 	separator.
 *  Only one 'c' is considered as separator when it appears one behind other 'c'
 *
 *  RETURN
 *  - A pointer of string pointers finished with NULL
 */

static unsigned int	getnsubstr(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (n);
}

static void	free_split_arr( int i, char **arr)
{
	while (i > -1)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

static int	mysplit(char const *s, char c, unsigned int nsubstr, char **spl_arr)
{
	unsigned int	ips;
	unsigned int	i;
	unsigned int	start;
	char			*newsub;

	i = 0;
	ips = 0;
	while (ips < nsubstr)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		newsub = ft_substr(s, start, i - start);
		if (!newsub)
		{
			free_split_arr(ips - 1, spl_arr);
			return (0);
		}
		spl_arr[ips++] = newsub;
	}
	spl_arr[nsubstr] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**split_arr;
	unsigned int	nsubstr;
	int				issplit;

	nsubstr = getnsubstr(s, c);
	split_arr = (char **) malloc(sizeof(char *) * (nsubstr + 1));
	if (split_arr && s && *s && nsubstr)
	{
		issplit = mysplit(s, c, nsubstr, split_arr);
		if (!issplit)
			return (NULL);
	}
	else if (split_arr)
		split_arr[0] = NULL;
	return (split_arr);
}
