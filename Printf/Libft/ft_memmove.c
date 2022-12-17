/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:34:00 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/22 14:34:00 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//Se src < dest(caso overlapping) entao a src 
//comeca do final da src(do n basicamente) 
//Se src > dest entao a src comeca do inicio da src(do n basicamente)
//Esta funcao faz o mesmo do memcpy mas faz melhor porque protege de overlaping
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	len;

	len = 0;
	if (!src && !dest)
		return (dest);
	if (src < dest)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
			len++;
		}
	}
	return (dest);
}

// int main()
// {
//     char oi[10] = "ola";
//     printf("mine %s\n", (char *)ft_memmove(oi, "banako", 4));
//     printf("their %s\n", (char *)memmove(oi, "banako", 4));
// }