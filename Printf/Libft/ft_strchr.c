/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:35:18 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/22 21:35:18 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//O valor vai dar wrap around se for maior que 255, ou seja, 
//256 representa o algarismo NULL da tabela ascii
//300 representa o 1 da tabela de ascii, etc
//Retorna a palavra a partir do primeiro elemento c que encontrar
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

// int main()
// {
//     // printf("meu %s\n", ft_strchr("banana", '\0'));
//     // printf("deles %s\n", strchr("banana", '\0'));
// 	printf("meu %s\n", ft_strchr("tripouille",'t' + 256));
//     printf("deles %s\n", strchr("tripouille",'t' + 256));
// }