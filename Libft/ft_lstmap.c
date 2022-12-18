/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:55:51 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/31 14:58:18 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	newlist = ft_lstnew((*f)(lst->content));
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		ft_lstadd_back(&newlist, temp);
		lst = lst->next;
	}
	return (newlist);
}
