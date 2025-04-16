/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:19:33 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/30 19:32:53 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

/*
 * Delete the content and free the node pointed by "*lst" and the nexts nodes
 * Finally "*lst" must be NULL.
 */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*paux;

	while (*lst)
	{
		paux = (*lst)->next;
		del((*lst)->content);
		(*lst)->content = NULL;
		free(*lst);
		*lst = paux;
	}
	*lst = NULL;
}
