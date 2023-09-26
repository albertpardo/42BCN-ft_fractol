/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:15:58 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/20 14:43:22 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
 *	Send the char 'c' to stdio
 *
 *	Returns:
 *		- 1  for char writed
 *		- -1 for error
 */

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
