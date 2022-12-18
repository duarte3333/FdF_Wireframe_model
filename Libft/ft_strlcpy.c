/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:39:15 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/22 21:39:15 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Funciona como strncpy mas garante o terminio da str com \0
//copia size - 1 elementos e para garantir o \0 no final
//Versao melhorada do strncpy
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (size != 0)
	{
		while (*src && (size - 1))
		{
			*dest = *src;
			dest++;
			src++;
			size--;
		}
		*dest = '\0';
	}
	return (src_size);
}

// int main()
// {
//     char dest[10] = "ola";
//     char src[10] = "banako";
//     ft_strlcpy(dest, src, 3);
//     printf("mine %s\n", dest);
// }