/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:47:07 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/22 21:47:07 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkfront(const char *s, int c)
{
	s++;
	while (*s)
	{
		if (*s == (char)c)
			return (0);
		s++;
	}
	return (1);
}

//Retorna a palavra a partir do ultimo elemento c que encontrar
char	*ft_strrchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c && ft_checkfront(s, c))
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

// int main()
// {
//     printf("meu %s\n", ft_strrchr("banana", 'a'));
//     printf("deles %s\n", strrchr("banana", 'a'));
// }