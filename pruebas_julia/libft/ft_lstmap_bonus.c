/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:57:29 by apardo-m          #+#    #+#             */
/*   Updated: 2023/06/13 16:06:14 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
 * Create a new list iterating for each "*lst" node applyng the function "f"
 * If there is any memory problem, all the new content and new list must be
 * deleted with the funciton "del" and the new nodes and new list must be free.
 *
 * Return :
 *  - A new list appliying "f" in each node of original "*lst"
 *  - NULL if thereis a memory problem
 *
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*newnode;
	void	*newcontent;

	nlst = NULL;
	while (lst && f && del)
	{
		newcontent = f(lst->content);
		newnode = ft_lstnew(newcontent);
		if (newcontent && newnode)
		{
			ft_lstadd_back(&nlst, newnode);
			lst = lst->next;
		}
		else
		{
			del(newcontent);
			ft_lstclear(&newnode, del);
			ft_lstclear(&nlst, del);
			return (NULL);
		}
	}
	return (nlst);
}
