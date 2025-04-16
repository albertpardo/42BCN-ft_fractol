/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:10:44 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/12 13:40:35 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Returns
 * 	The position of the last occurrence of "(char) c" in "*s".
 * 		 If c == '\0' is part of the string
 * 	NULL for no ocurrence
 */

char	*ft_strrchr(const char *s, int c)
{
	const char		*ptr;
	unsigned char	un_c;

	un_c = (unsigned char) c;
	ptr = s;
	while (*ptr != '\0')
		ptr++;
	while (ptr != s && *ptr != un_c)
		ptr--;
	if (ptr == s && *ptr != un_c)
		ptr = 0;
	return ((char *) ptr);
}
