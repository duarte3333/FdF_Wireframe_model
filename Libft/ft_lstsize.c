/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:51:19 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/25 17:34:56 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Esta funcao calcula o tamanho de uma linked list
int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
// int main()
// {
// 	t_list* head = NULL;
// 	t_list* second = NULL;
// 	t_list* third = NULL;
// 	head = (t_list*)malloc(sizeof(t_list));
// 	second = (t_list*)malloc(sizeof(t_list));
// 	third = (t_list*)malloc(sizeof(t_list));

// 	head->data = 1; // assign data in first node
// 	head->next = second; // Link first node with
// 	second->data = 2;
// 	second->next = third;
// 	third->data = 3; // assign data to third node
// 	third->next = NULL;
// 	printf("%i\n", ft_lstsize(head));
// }