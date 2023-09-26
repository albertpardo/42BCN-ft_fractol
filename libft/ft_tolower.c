/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:32:10 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/13 09:49:24 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * upper-case letter to lower-case letter
 */

int	ft_tolower(int c)
{
	int	result;

	result = c;
	if (c > 64 && c < 91)
		result = c + 32;
	return (result);
}
