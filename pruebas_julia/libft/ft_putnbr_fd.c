/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:35:58 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/13 14:39:14 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
 * Put integer number 'n' in the file descriptor "fd" in char format
 */

static void	putposint(int num, int fd)
{
	if (num < 10)
	{
		ft_putchar_fd(num + '0', fd);
		return ;
	}
	putposint(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if ((n < 0) && (n != -2147483648))
	{
		n = n * -1;
		ft_putchar_fd('-', fd);
	}
	if (n >= 0)
		putposint(n, fd);
	else
		write(fd, "-2147483648", 11);
}
