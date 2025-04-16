/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:20:51 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/13 14:32:44 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/*
 *	Send the char 'c' to the specific file descirptor "fd"
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
