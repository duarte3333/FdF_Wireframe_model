/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:35:51 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/22 14:35:51 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Ocupa n bytes com o elemento c a partir 
//do elemento para o qual s está a apontar
void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	int		i;

	i = -1;
	str = (char *)s;
	while (n > 0)
	{
		str[++i] = c;
		n--;
	}
	return (s);
}

// int main()
// {
//     char str[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\nBefore memset(): %s\n", str);
//     // Fill 8 characters starting from str[13] with '.'
//     ft_memset(str + 13, 0, 8*sizeof(char));
//     printf("After memset():  %s", str);
//     return 0;
// }