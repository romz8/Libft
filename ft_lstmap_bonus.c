/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:27:47 by rjobert           #+#    #+#             */
/*   Updated: 2023/05/12 20:00:40 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	node = ft_lstnew((*f)(lst->content));
	if (!node)
		return (NULL);
	cpy = node;
	lst = lst->next;
	while (lst)
	{
		node = ft_lstnew((*f)(lst->content));
		if (!node)
		{
			return (NULL);
		}	
		ft_lstadd_back(&cpy, node);
		lst = lst->next;
	}
	return (cpy);
}
