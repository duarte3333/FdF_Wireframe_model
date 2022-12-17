/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:38:58 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/10/22 21:38:58 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Esta funcao vai concatenar duas str, a src ao dest
//Se o size for 3, dest 5, src 4 ele retorna 4+3=7
//Se o size for 0, dest 5, src 4 ele retorna 4+0=4
//Se o size for 7, dest 5, src 4 ele retorna 4+5=9
//So vai dar cat de (size - dlen - 1) no maximo
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
