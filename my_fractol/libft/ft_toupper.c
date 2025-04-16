/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:32:47 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/13 09:49:27 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * lower-case letter to upper-case letter
 */

int	ft_toupper(int c)
{
	int	result;

	result = c;
	if (c > 96 && c < 123)
		result = c - 32;
	return (result);
}
