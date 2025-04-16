/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:22:35 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/13 14:38:33 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
 * Sends the string "str" to the file descriptor "fd", and apply a carry return
 */

void	ft_putendl_fd(char *str, int fd)
{
	if (str != NULL)
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
}
