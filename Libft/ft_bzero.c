/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:42:27 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/22 12:42:27 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//Ocupa n bytes com NULL a partir do elemento para o qual s está a apontar
void	ft_bzero(void *s, size_t n)
{
	char	*str;
	int		i;

	i = -1;
	str = (char *)s;
	while (n > 0)
	{
		str[++i] = 0;
		n--;
	}
}
// int main()
// {
//     char str[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\nBefore memset(): %s\n", str);
//     // Fill 8 characters starting from str[13] with '.'
//     ft_bzero(str + 13, 2*sizeof(char));
//     printf("After memset():  %s", str);
//     return 0;
// }