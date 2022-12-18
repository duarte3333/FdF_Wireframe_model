/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:40:56 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/22 21:40:56 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checknexts(char *big, char *little, size_t len)
{
	while (*little && (*big == *little) && len)
	{
		if (*big == *little)
		{
			big++;
			little++;
		}
		else
			return (0);
		len--;
	}
	if (*little == 0)
		return (1);
	return (0);
}

//Esta funcao procura o little ate len e caso encontre
//retorna o o big desde o primeiro elemento onde encontrou o little
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*temp;

	temp = little;
	if (*little == '\0' || little == NULL)
		return ((char *)big);
	while (*big && len)
	{
		little = temp;
		while (*little)
		{
			if ((*big == *little) && \
			ft_checknexts((char *)big, (char *)temp, len))
				return ((char *)big);
			little++;
		}
		big++;
		len--;
	}
	return (0);
}
// int main ()
// {
//     char oi[1000] = "dsutesqdweasasdsda";
//     printf("mine %s\n", ft_strnstr(oi, "sda", 1000));
//     printf("mine %s\n", ft_strnstr("dolor sit amet", "dolor", 5));
//     //printf("their %i\n", strnstr(oi, "n", 4));
// }