/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:30:06 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/31 01:05:18 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//t_list **lst equivale a uma list de linked lists
//Esta funcao adiciona um elemento ao inicio
//da linked list, colocando o new->next a apontar
//para o primeiro elemento da linked list recebida
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}

// int main()
// {
// 	t_list	**p;
// 	t_list	*head = NULL;
// 	t_list	*second = NULL;
// 	t_list	*third = NULL;
// 	t_list	*new = NULL;

// 	new = (t_list *)malloc(sizeof(t_list));
// 	head = (t_list *)malloc(sizeof(t_list));
// 	second = (t_list *)malloc(sizeof(t_list));
// 	third = (t_list *)malloc(sizeof(t_list));

// 	head->data = 1;
// 	head->next = second;
// 	second->data = 2;
// 	second->next = third;
// 	third->data = 3;
// 	third->next = NULL;

// 	new->data = 10;
// 	new->next = NULL;
// 	p = &head;
// 	//printf("%i\n", ft_lstadd_front(p, new));
// 	ft_lstadd_front(p, new);
// 	while (head)
// 	{
// 		printf("%i\n", (head)->data);
// 		head = head->next;
// 	}
// }
