/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:36:20 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/13 15:45:44 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

/*
 * Delete/ free the memory from de node pointed by "*lst*".
 * Steps
 * 		1 - Delete/Free the "content" memory with the function "del"
 * 		2 - Delete/Free the node pinted by "*lst"
 * 		3 - Do Nothing with lst->next
 */

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
